#ifndef context_h
#define context_h

#include <string>
#include <map>
#include <exception>

class ExceptionContexte : public std::exception {
	public:
	ExceptionContexte(std::string);

	const char * what() const noexcept override;
private:
	std::string _errmsg;
};

class Contexte {
private:
    std::map<std::string, double> variables;
public:
    Contexte() = default;
    Contexte(const Contexte & autre) = default;

    double& get(const std::string & nom);
    const double& get(const std::string & nom) const;

    double& operator[](const std::string & nom);
    const double& operator[](const std::string & nom) const;

};


#endif