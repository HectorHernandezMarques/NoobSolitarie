#ifndef UTILS_IO_H_
#define UTILS_IO_H_

#include <string>
#include <iostream>
#include <climits>
#include <cassert>

namespace Utils {

class IO {
private:
	IO();
	static IO *io;
public:
	virtual ~IO();

	int readInt(std::string title);
	std::string readString(std::string title);
	void write(std::string text);
	void writeln(std::string text);

	static IO& getInstance();
};

} /* namespace Utils */

#endif /* UTILS_IO_H_ */
