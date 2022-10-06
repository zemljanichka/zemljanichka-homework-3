#include <string>
#include <algorithm>

class Object {
	public:
		Object() = default;

		std::string getName();
		std::string getPath();
		Object& withPath(std::string path);

	private:
		std::string path;
};
