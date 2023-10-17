#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <iostream>
#include <exception>
#include <sstream>

class ExceptionChaine : public std::exception {
public:
  ExceptionChaine(const std::string& message) : m_message(message) {}
  const char* what() const noexcept override { return m_message.c_str(); }
private:
  std::string m_message;
};

template <typename T>
std::string chaine(const T& x) {
  throw ExceptionChaine("Conversion en chaine impossible pour '" + std::string(demangle(typeid(x).name())) + "'");
}

std::string chaine(const std::string& x) {
  return x;
}

std::string chaine(const int& x) {
  return std::to_string(x);
}

std::string chaine(const double& x) {
  return std::to_string(x);
}

#endif /* CHAINE_HPP */