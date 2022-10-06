#include "RestorePoint.h"

RestorePoint::RestorePoint(const std::vector<Object>& obj, const std::string& algo, const std::string& path, int num) {
	if (algo == "Split") {
		savedObjects = obj;
		for (auto & savedObject : savedObjects) {
			std::string storage = (path + savedObject.getName());
			storage += ("_" + std::to_string(num) + ".zip");
			savedObject = savedObject.withPath(storage);
		}
	} else {
		Object a;
		std::string storage = (path + "Single_Storage_" + std::to_string(num) + ".zip");
		savedObjects.push_back(a.withPath(storage));
	}
}

std::vector<Object> RestorePoint::getStorages() {
	return savedObjects;
}
