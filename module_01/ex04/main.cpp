/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:22:06 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 18:46:16 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replace_in_file(std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: " << filename << "could not be opened." << std::endl;
		return;
	}

	std::string file_content;
	std::getline(inputFile, file_content, '\0');
	inputFile.close();

	if (file_content.empty())
	{
		std::cerr << "Error: " << filename << " is empty." << std::endl;
		return;
	}

	int founded_index = file_content.find(s1);
	while (founded_index != -1)
	{
		file_content.erase(founded_index, s1.length());
		file_content.insert(founded_index, s2);
		founded_index = file_content.find(s1);
	}

	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: " << filename << ".replace can't open." << std::endl;
		return;
	}
	outputFile << file_content;
	outputFile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: invalid argument count." << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <search_string> <replace_string>" << std::endl;
        return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	replace_in_file(filename, s1, s2);

	return 0;
}
