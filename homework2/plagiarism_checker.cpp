#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator> // 需要包含这个头文件以使用std::inserter

// Helper function to split a string into words
std::vector<std::string> splitToWords(const std::string& line) {
	std::istringstream iss(line);
	std::vector<std::string> words;
	std::string word;
	while (iss >> word) {
		words.push_back(word);
	}
	return words;
}

// Function to calculate similarity score
double calculateSimilarity(const std::vector<std::string>& original, const std::vector<std::string>& plagiarized) {
	std::set<std::string> originalSet(original.begin(), original.end());
	std::set<std::string> plagiarizedSet(plagiarized.begin(), plagiarized.end());

	std::set<std::string> intersectionSet;
	std::set_intersection(originalSet.begin(), originalSet.end(),
		plagiarizedSet.begin(), plagiarizedSet.end(),
		std::inserter(intersectionSet, intersectionSet.begin()));

	double intersectionSize = intersectionSet.size();
	double unionSize = originalSet.size() + plagiarizedSet.size() - intersectionSize;

	return unionSize == 0 ? 0.0 : (intersectionSize / unionSize);
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <original_file> <plagiarized_file> <output_file>" << std::endl;
		return 1;
	}

	std::ifstream originalFile(argv[1]);
	std::ifstream plagiarizedFile(argv[2]);
	std::ofstream outputFile(argv[3]);

	if (!originalFile.is_open() || !plagiarizedFile.is_open()) {
		std::cerr << "Error opening input files!" << std::endl;
		return 1;
	}
	if (!outputFile.is_open()) {
		std::cerr << "Error opening output file!" << std::endl;
		return 1;
	}

	std::string line;
	std::vector<std::string> originalWords, plagiarizedWords;

	// Read original file content
	while (std::getline(originalFile, line)) {
		auto words = splitToWords(line);
		originalWords.insert(originalWords.end(), words.begin(), words.end());
	}

	// Read plagiarized file content
	while (std::getline(plagiarizedFile, line)) {
		auto words = splitToWords(line);
		plagiarizedWords.insert(plagiarizedWords.end(), words.begin(), words.end());
	}

	// Calculate similarity
	double similarity = calculateSimilarity(originalWords, plagiarizedWords);

	// Output the similarity score
	outputFile << std::fixed;
	outputFile.precision(2);
	outputFile << similarity * 100 << "%" << std::endl;

	originalFile.close();
	plagiarizedFile.close();
	outputFile.close();

	return 0;
}