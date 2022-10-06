#include "Repository.h"

void Disk::write(RestorePoint rp, JobObject jo) {
	unsigned id1 = 0;
	for (auto& i: jo.getJobObject()) {
		std::string comand = "zip ";
		comand += (rp.getStorages()[id1].getPath() + " " + i.getPath());
		system(comand.c_str());
		if (id1 + 1 < rp.getStorages().size())
			id1++;
	}
}

Repository::Repository(const std::string& type) {
	if (type == "Disk")
		fs = new Disk();
	else
		fs = new VirtualDisk();
}

void Repository::write(RestorePoint rp, JobObject jo) {
	fs->write(rp, jo);
}
