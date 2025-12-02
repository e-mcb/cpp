#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);

	std::string filename = getTarget() + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (!ofs) return;

	FILE* pipe = popen("tree -L 1", "r");
	if (!pipe)
		return;
	char buffer[128];
	std::stringstream ss;
	while (fgets(buffer, sizeof(buffer), pipe))
		ss << buffer;
	pclose(pipe);
	ofs << ss.str();
}



std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
	out << "ShrubberyCreationFormm: " << form.getName()
		<< ", Sign Grade: " << form.getSignGrade()
		<< ", Exec Grade: " << form.getExecGrade()
		<< ", Signed: " << (form.getSignedStatus() ? "Yes" : "No")
		<< ", Target: " << form.getTarget();
	return out;
}