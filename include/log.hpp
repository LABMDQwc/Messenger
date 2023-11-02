#pragma once

#include <chrono>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <thread>

#define LOG_FILE "log.log"

namespace chrono = std::chrono;

class Logger {
 private:
  std::fstream _log;
  std::mutex _mutex;

 public:
  Logger();

  ~Logger();

  void write(const std::string&, const std::string&);
};

#define WRITE_LOG(message, level) \
  std::thread([&]() { log.write(message, level); }).detach();
