/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-04-21 14:46:49
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-04-21 14:47:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// 递归遍历目录
void traverse_directory(const char *path)
{
	DIR *dir;
	struct dirent *entry;
	struct stat statbuf;

	// 打开目录
	if ((dir = opendir(path)) == NULL)
	{
		perror("opendir");
		return;
	}

	// 遍历目录中的每个条目
	while ((entry = readdir(dir)) != NULL)
	{
		char new_path[1024];

		// 构建新路径
		snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);

		// 获取文件信息
		if (stat(new_path, &statbuf) == -1)
		{
			perror("stat");
			continue;
		}

		// 如果是目录，递归遍历
		if (S_ISDIR(statbuf.st_mode))
		{
			// 跳过当前目录和上级目录
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			{
				continue;
			}
			traverse_directory(new_path);
		}
		else
		{
			// 对文件执行操作，这里只是打印文件路径
			printf("File: %s\n", new_path);
		}
	}

	// 关闭目录
	closedir(dir);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
		return 1;
	}

	// 开始遍历指定目录
	traverse_directory(argv[1]);

	return 0;
}