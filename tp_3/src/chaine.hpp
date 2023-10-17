#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <iostream>
#include <exception>

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

#endif /* CHAINE_HPP */