/*
 * Dreamos
 * vfs.c
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
#include <video.h>
#include <vfs.h>
#include <stdio.h>
#include <kheap.h>
#include <stddef.h>
#include <string.h>
#include <kheap.h>
#include <unistd.h>

struct mountpoint_t mountpoint_list[MAX_MOUNTPOINT];

void vfs_init(){
	int i=0;
 	printf("\nPreparing VFS\n");
 	while(i<MAX_MOUNTPOINT) {
 		strcpy(mountpoint_list[i].mountpoint,"");
 		mountpoint_list[i].uid = 0;
 		mountpoint_list[i].gid = 0;
 		mountpoint_list[i].pmask = 0;
 		mountpoint_list[i].dev_id = 0;
	 	mountpoint_list[i].start_address = 0;
	 	mountpoint_list[i].operations = NULL;
 		i++;
	}
	
 	strcpy(mountpoint_list[0].mountpoint,"/");
 	mountpoint_list[0].uid = 0;
 	mountpoint_list[0].gid = 0;
 	mountpoint_list[0].pmask = 0;
 	mountpoint_list[0].dev_id = 0;
 	mountpoint_list[0].start_address = 0;
 	mountpoint_list[0].operations = kmalloc(sizeof(struct super_node_operations));

	strcpy(mountpoint_list[1].mountpoint,"/dev"); 	
	mountpoint_list[1].uid = 0;
 	mountpoint_list[1].gid = 0;
 	mountpoint_list[1].pmask = 0;
 	mountpoint_list[1].dev_id = 0;
 	mountpoint_list[1].start_address = 0;
 	mountpoint_list[1].operations = kmalloc(sizeof(struct super_node_operations));
	
	strcpy(mountpoint_list[2].mountpoint,"/dev/video"); 	
	mountpoint_list[2].uid = 0;
 	mountpoint_list[2].gid = 0;
 	mountpoint_list[2].pmask = 0;
 	mountpoint_list[2].dev_id = 0;
 	mountpoint_list[2].start_address = 0;
 	mountpoint_list[2].operations = kmalloc(sizeof(struct super_node_operations));
	
	strcpy(mountpoint_list[3].mountpoint,"/root");
 	mountpoint_list[3].uid = 0;
 	mountpoint_list[3].gid = 0;
 	mountpoint_list[3].pmask = 0;
 	mountpoint_list[3].dev_id = 0;
 	mountpoint_list[3].start_address = 0;
 	mountpoint_list[3].operations = kmalloc(sizeof(struct super_node_operations));

}

void open_vfs (struct inode *node){
	if(node->read!=0) printf("read node");
	else return;
}

int get_mountpoint_id(char *path){
       int i = 0;
       int last;
	   last = -1;	   	 
       while(i<MAX_MOUNTPOINT ){
                       if(!_kstrncmp(path, mountpoint_list[i].mountpoint, strlen(mountpoint_list[i].mountpoint))) {                 
							   if(strlen(mountpoint_list[i].mountpoint) > strlen(mountpoint_list[last].mountpoint) && i>0)  
                               		last = i;
							   else last = i;
                       }					   					   
                       i++;
               }
			   if(last!=-1) printf("Changing dir %s\n", mountpoint_list[last].mountpoint, last);
               return last;
}

char *get_rel_path(int mountpoint_id, char* path){
	int rel_size = 0;
	int j=0;
	char *tmp_path;
	rel_size = strlen(path) - strlen(mountpoint_list[mountpoint_id].mountpoint);	
	if(rel_size>0){		
		int mp_size= 0;
		tmp_path = kmalloc(rel_size * sizeof(char));		
		mp_size = strlen(mountpoint_list[mountpoint_id].mountpoint);		
		while(j<rel_size){			
			tmp_path[j] = path[mp_size + j];			
			j++;
		}
		tmp_path[j]='\0';
	}	
	return tmp_path;
}