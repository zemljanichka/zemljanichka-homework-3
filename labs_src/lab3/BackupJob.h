#pragma once

#include <vector>
#include "Repository.h"

class BackupJob {
	public:
		JobObject jo;

		explicit BackupJob(std::string typeFS);
		~BackupJob();

		void addObject(std::string path);
		void rmObject(std::string path);
		void createRestorePoint(const std::string& algo, const std::string& path);
		std::vector<Object> getJobObject();
		std::vector<RestorePoint> getRestorePoints();

	private:
		Repository *r;
		std::vector<RestorePoint> rPoints;
};
