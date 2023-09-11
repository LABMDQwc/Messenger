#include "../include/log.hpp"

Logger::Logger() : log(LOG_FILE, std::ios::app) {}

Logger::~Logger() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  log.close();
}

void Logger::write(const std::string& msg, const std::string& level) {
  auto now = std::chrono::system_clock::to_time_t(chrono::system_clock::now());
  mutex.lock();
  log << level << std::put_time(localtime(&now), "%c") << "\t" << msg
      << std::endl;
  mutex.unlock();
}
