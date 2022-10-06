#include "BackupJob.h"

BackupJob::BackupJob(std::string typeFS) {
	r = new Repository(typeFS);
}

BackupJob::~BackupJob() {
	delete r;
}

void BackupJob::addObject(std::string path) {
	jo.addObject(path);
}

void BackupJob::rmObject(std::string path) {
	jo.rmObject(path);
}

void BackupJob::createRestorePoint(const std::string& algo, const std::string& path) {
	auto *a = new RestorePoint(jo.getJobObject(), algo, path, int(rPoints.size() + 1));
	rPoints.push_back(*a);
	r->write(*a, jo);
	delete a;
}

std::vector<Object> BackupJob::getJobObject() {
	return jo.getJobObject();
}

std::vector<RestorePoint> BackupJob::getRestorePoints() {
	return rPoints;
}
