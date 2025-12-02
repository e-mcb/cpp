#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& text, const std::string& s1, const std::string& s2)
{
	if (s1.empty())
		return text;

	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = text.find(s1, pos)) != std::string::npos)
	{
		result += text.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += text.substr(pos);
	return result;
}

int main(int argc, char** argv) 
{
	if (argc != 4) 
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) 
	{
		std::cerr << "Error: s1 cannot be an empty string." << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile) 
	{
		std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
		return 1;
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile) 
	{
		std::cerr << "Error: Could not create output file '" << filename + ".replace" << "'" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(infile, line)) 
	{
		outfile << replaceAll(line, s1, s2);
		if (!infile.eof())
			outfile << '\n';
	}

	infile.close();
	outfile.close();

	return 0;
}
