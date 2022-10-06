#include <gtest/gtest.h>
#include "lab3/BackupJob.h"

TEST(CreateBackups, TwoRestorePointsAndThreeStoragesCreated) {
    BackupJob a("Virtual Disk");
    a.addObject("FileA");
    a.addObject("FileB");

    a.createRestorePoint("Split", "test/a/b/c/");

    a.rmObject("FileB");

    a.createRestorePoint("Split", "test/a/b/c/");

    int storages = 0;
    for (auto& i: a.getRestorePoints())
        storages += i.getStorages().size();

    ASSERT_EQ(a.getRestorePoints().size(), 2);
    ASSERT_EQ(storages, 3);
}
