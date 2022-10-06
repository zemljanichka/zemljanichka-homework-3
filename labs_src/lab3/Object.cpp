#include "Object.h"

std::string Object::getName() {
	return path.substr(path.find_last_of('/') + 1);
}

std::string Object::getPath() {
	return path;
}

Object& Object::withPath(std::string path) {
	this->path = path;
	return *this;
}
