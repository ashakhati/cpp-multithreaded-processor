
#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>

class JobQueue
{
public:
    void addJob(const std::string& job);
    bool getJob(std::string& job);
    void stop();

private:
    std::queue<std::string> jobs;
    std::mutex mtx;
    std::condition_variable cv;
    bool stopped = false;
};