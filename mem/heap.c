/***************************************************************************
 *            heap.c
 *
 *  Sun 8 08 10 
 *  Copyright  2010  Ivan Gualandri
 *  Email finarfin@elenhost.org
 ****************************************************************************/
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <heap.h>
#include <stdio.h>

extern unsigned int end;
new_heap_t *n_heap=0;
void new_heap(unsigned int start, unsigned int size){
	new_heap_t* t_heap = new_malloc(sizeof(new_heap_t));
	if(start%0x1000 == 0) printf("all right\n");
	else printf("ERROR\n");
}

unsigned int new_malloc(unsigned int size){
	if(n_heap==0) {
		printf("No heap defined starting from: %d ...\n", &end);
	}
	else {
		printf("Heap defined\n");
	}
}