#pragma once

#include <Arduino.h>

enum LogLevel
{
  INFO,
  WARNING,
  ERROR,
  DEBUG
};

class Logger
{
  private:
    const char* getLevelName(LogLevel level);
    void log(LogLevel level, const char* source, const char* message);

  public:
    Logger();

    void begin();
    void info(const char* source, const char* message);
    void warning(const char* source, const char* message);
    void error(const char* source, const char* message);
    void debug(const char* source, const char* message);
};