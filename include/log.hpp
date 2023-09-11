#pragma once

#include <chrono>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <thread>

#define LOG_FILE "log.log"

#define DEBUG "\033[38;2;88;199;127m[DEBUG]\033[0m    "
#define INFO "\033[32m[INFO]\033[0m     "
#define WARNING "\033[38;2;179;165;75m[WARNING]\033[0m  "
#define ERROR "\033[38;2;199;141;88m[ERROR]\033[0m    "
#define FATAL "\033[38;2;199;88;88m[FATAL]\033[0m    "

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
