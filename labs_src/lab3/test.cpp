#include <iostream>
#include "BackupJob.h"
#include "Repository.h"

int main() {
	BackupJob a("Disk");

	a.addObject("data/file1");
	a.addObject("data/file2");
	a.addObject("data/file3");

	a.createRestorePoint("Split", "backup/");
	a.createRestorePoint("Single", "backup/");

	a.rmObject("data/file3");

	a.createRestorePoint("Split", "backup/");
	a.createRestorePoint("Single", "backup/");
}
