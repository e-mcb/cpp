#include <string>
#include <iostream>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

class Contact 
{
public:
	Contact(void);
	~Contact(void);
	void setFirstName(const std::string &fn);
	void setLastName(const std::string &ln);
	void setNickname(const std::string &nn);
	void setPhoneNumber(const std::string &pn);
	void setDarkestSecret(const std::string &ds);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};