#include "Logger.h"

Logger::Logger()
{
}

void Logger::begin()
{
  Serial.begin(115200);
}

const char* Logger::getLevelName(LogLevel level)
{
  switch(level)
  {
    case INFO:
      return "INFO";

    case WARNING:
      return "WARNING";

    case ERROR:
      return "ERROR";

    case DEBUG:
      return "DEBUG";
  }

  return "UNKNOWN";
}

void Logger::log(LogLevel level, const char* source, const char* message)
{
  Serial.print("[");
  Serial.print(getLevelName(level));
  Serial.print("] [");
  Serial.print(source);
  Serial.print("] ");
  Serial.println(message);
}

void Logger::info(const char* source, const char* message)
{
  log(INFO, source, message);
}

void Logger::warning(const char* source, const char* message)
{
  log(WARNING, source, message);
}

void Logger::error(const char* source, const char* message)
{
  log(ERROR, source, message);
}

void Logger::debug(const char* source, const char* message)
{
  log(DEBUG, source, message);
}