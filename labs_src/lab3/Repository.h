#pragma once

#include <cstring>
#include "JobObject.h"
#include "RestorePoint.h"

class FileSystem {
	public:
		virtual void write(RestorePoint rp, JobObject jo) = 0;
};

class VirtualDisk: public FileSystem {
	public:
		VirtualDisk() {}
		void write(RestorePoint rp, JobObject jo) {
			(void)rp;  // explicitly unused
			(void)jo;  // explicitly unused
		}
};

class Disk: public FileSystem {
	public:
		Disk() {}
		void write(RestorePoint rp, JobObject jo);
};


class Repository {
	public:
		explicit Repository(const std::string& type);

		std::string getPath();
		void write(RestorePoint rp, JobObject jo);

	private:
		std::string path;
		FileSystem *fs;
};
