

#include <globals.h>


// 保证文件的存在，不在则创建。
void assure_file(string file)
{
	int i, j;
	string path, *dir;
	write(" --|--	simul_efun.c中的assure_file()被调用。\n");



	if (file_size(file) != -1)
		return;

	dir = explode(file, "/");
	dir = dir[0..sizeof(dir) - 2];
	path = "/";
	
	for ( i = 0, j = sizeof(dir); i < j; i++)
	{
		path += dir[i];
		mkdir(path);	//创建文件夹
		path += "/";
	}
	return;
}
// 打log用的
void log_file(string file, string arg)
{	
	write(" --|--	simul_efun.c中的log_file()被调用。\n");


    catch(assure_file(LOG_DIR+file));	//确保log文件的存在？
	catch(write_file(LOG_DIR+file, arg));	// 写文件操作，是mudos中的。
	return;
}

string base_name(object ob)
{
	write(" --|--	simul_efun.c中的base_name()被调用。\n");
	
	
	return explode(file_name(ob), "#")[0];
}

