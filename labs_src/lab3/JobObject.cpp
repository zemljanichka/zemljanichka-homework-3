#include "JobObject.h"

void JobObject::addObject(std::string path) {
	for (auto & object : objects)
		if (object.getPath() == path)
			return;

	auto *a = new Object();
	objects.push_back(a->withPath(path));
	delete a;
}

void JobObject::rmObject(std::string path) {
	objects.erase(
		std::remove_if(objects.begin(), objects.end(), [path](auto& i){
			return (i.getPath() == path);
		}),
		objects.end());
}

std::vector<Object> JobObject::getJobObject() {
	return objects;
}
