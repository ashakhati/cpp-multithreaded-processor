
#include "JobQueue.h"

#include <iostream>
#include <thread>
#include <vector>

void worker(JobQueue& queue, int workerId)
{
    std::string job;

    while (queue.getJob(job))
    {
        std::cout << "Worker " << workerId
                  << " processing: " << job << '\n';
    }


    std::cout << "Worker " << workerId << " stopped.\n";
}

int main()
{
    JobQueue queue;

    std::vector<std::thread> workers;

    for (int i = 1; i <= 3; ++i)
    {
        workers.emplace_back(worker, std::ref(queue), i);
    }

    for (int i = 1; i <= 10; ++i)
    {
        queue.addJob("Job " + std::to_string(i));
    }

    queue.stop();

    for (auto& thread : workers)
    {
        thread.join();
    }

    std::cout << "All jobs completed.\n";

    return 0;
}