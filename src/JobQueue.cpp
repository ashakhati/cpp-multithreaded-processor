
#include "JobQueue.h"

void JobQueue::addJob(const std::string& job)
{
    {
        std::lock_guard<std::mutex> lock(mtx);

        if (stopped)
        {
            return;
        }

        jobs.push(job);
    }

    cv.notify_one();
}

bool JobQueue::getJob(std::string& job)
{
    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock, [this]
    {
        return !jobs.empty() || stopped;
    });

    if (jobs.empty())
    {
        return false;
    }

    job = jobs.front();
    jobs.pop();

    return true;
}

void JobQueue::stop()
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        stopped = true;
    }

    cv.notify_all();
}
