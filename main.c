/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 09:50:17 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/29 13:07:44 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtest.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <libft.h>


void wrfile(char *fname){
	char *line;

	int file = open(fname, O_RDONLY);
	char *ofilename = ft_strcat(ft_strdup(fname), ".out");
	int ofile = open(ofilename, O_CREAT | O_WRONLY, 0777);
	while (get_next_line(file, &line) > 0){
		write(ofile, line, ft_strlen(line));
		write(ofile, "\n", 1);
	}
	close(file);
	close(ofile);
}

void make_tcmp(char *str, char *fname)
{
	int w = open(fname, O_CREAT | O_WRONLY, 0777);
	write(w, str, strlen(str));
	close(w);
}

int main(void)
{
	char *Test4 = "1234\n";
	char *Test127 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas tincidunt, nisl eget semper pharetra, tellus massa cras amet.\n";
	char *Test255 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam dictum enim sed pulvinar pellentesque. Sed quis ullamcorper urna. Curabitur hendrerit eleifend fringilla. Cras in interdum nunc, ac volutpat nibh. In fringilla tincidunt orci. Sed cras amet.\n";
	char *Test2048 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce cursus sed enim ut porttitor. In sit amet augue quis nibh blandit ultrices. Donec leo augue, gravida ut leo at, pharetra luctus odio. Morbi tristique, lorem eu aliquam lobortis, nibh erat blandit felis, sit amet dictum quam orci at mi. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Fusce vitae massa turpis. Suspendisse potenti. Vivamus iaculis sagittis neque et maximus. Fusce non consequat nunc, vitae interdum lacus. Phasellus elementum venenatis aliquam. Sed eu facilisis turpis. Donec fermentum scelerisque elit ut dictum. Vivamus quam tellus, posuere et fringilla eget, feugiat vitae dui. Mauris ullamcorper mi ac ante ornare finibus.\nAliquam sagittis varius ex, sit amet volutpat magna facilisis scelerisque. Nulla facilisi. Vivamus eu nunc eu mi vulputate sodales. Fusce quis orci luctus, vestibulum metus lacinia, accumsan tellus. Vestibulum convallis imperdiet vehicula. In hac habitasse platea dictumst. Aenean non magna mi. Etiam euismod, magna eu mattis tempus, erat ante vestibulum velit, vitae hendrerit metus ante vitae nulla. Nullam blandit ultricies leo, nec ornare neque pharetra vitae. Nunc eu consequat ligula, a consequat orci. Aliquam porta nec nunc at euismod.\nSuspendisse potenti. Fusce vel elementum elit, vel laoreet dolor. Fusce pellentesque tempor ante eget sollicitudin. Quisque vitae semper orci, sit amet hendrerit lacus. Suspendisse dolor ex, facilisis ullamcorper mauris at, iaculis aliquet est. Sed tincidunt justo quis neque venenatis, vel rhoncus lectus posuere. In accumsan mattis vehicula. Donec et elit vitae enim ultrices faucibus. Duis viverra sagittis finibus. Etiam eget lorem congue, egestas erat ut, sodales velit. Interdum et malesuada fames ac ante ipsum primis in faucibus. Duis efficitur, nisi sit amet porttitor sagittis, mauris sapien accumsan velit, vitae pretium massa arcu at turpis. Donec tristique vel justo pellentesque consectetur. Vestibulum faucibus lacus ullamcorper purus metus.\n";
	char *Test4096 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam a risus gravida, rhoncus velit vitae, porttitor diam. Maecenas at sodales nibh. Sed pellentesque porttitor nisl, nec pretium libero auctor id. Curabitur vitae condimentum metus. Vestibulum sit amet dui nulla. Morbi ante nibh, egestas nec mi vel, volutpat ultricies dolor. Mauris eget risus quis neque tincidunt tristique. Duis nibh dui, fringilla pellentesque suscipit vitae, blandit nec augue. Ut ipsum ex, malesuada vitae libero in, condimentum molestie elit. Donec tempus iaculis augue ut elementum. Suspendisse vulputate magna non vehicula viverra. Pellentesque aliquet rutrum mattis. Nulla facilisi. Curabitur nulla mi, sodales ut fringilla dignissim, interdum at sapien. Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nUt ut magna ultrices, viverra leo non, lobortis mauris. Donec at ornare magna. Nullam quis luctus purus. Vivamus dapibus, arcu ac bibendum dignissim, metus ex maximus nisi, id iaculis felis mi et ligula. Donec vitae quam vulputate quam maximus consequat et sit amet nibh. Nam scelerisque sem id justo facilisis hendrerit. Ut nec consectetur ipsum. Sed sed lobortis tortor.\nSuspendisse eu accumsan mi, sit amet auctor ante. Aliquam sodales, libero sed faucibus consectetur, turpis ex maximus est, et tempus libero ipsum nec nunc. Quisque nisl mi, gravida nec ultricies ut, dignissim quis urna. Fusce arcu velit, sagittis a efficitur id, ullamcorper ut enim. Praesent vel orci interdum, viverra eros ac, rhoncus risus. Etiam cursus vehicula ligula, quis tempus purus ultrices at. Ut ultrices arcu sit amet magna sollicitudin vestibulum. Donec sit amet nulla ut sem sodales luctus. Maecenas sodales sodales nulla, nec aliquam felis aliquet nec.\nEtiam auctor ipsum lectus, vel faucibus nibh congue et. Pellentesque semper vestibulum lorem vitae hendrerit. Sed eu purus sit amet velit dapibus semper. Sed tempus nibh eget quam eleifend efficitur. Phasellus condimentum mauris a quam commodo, nec tempus diam mollis. Sed aliquam elit purus, a vulputate lorem bibendum sit amet. Sed quis ultrices metus. Quisque ullamcorper commodo viverra. Phasellus eu lorem et risus tincidunt malesuada. Vestibulum ullamcorper id nisl non congue. Suspendisse ullamcorper eleifend dignissim. Aliquam vulputate ut lacus et congue.\nSed tincidunt, ipsum in molestie imperdiet, velit nibh ultrices tortor, sit amet dictum lectus lacus eget eros. Duis varius pretium nibh non placerat. Vestibulum feugiat placerat urna, in pharetra leo iaculis sit amet. Vestibulum ac diam ut arcu feugiat molestie quis in ex. Nunc hendrerit metus blandit eros venenatis, id rutrum urna euismod. Donec consectetur sem nibh, ac venenatis ante varius sed. Vivamus placerat dignissim ligula egestas dignissim. Curabitur vestibulum quam vitae sem venenatis sollicitudin. Pellentesque ex ligula, volutpat sed dictum non, vulputate semper nisi. Praesent consequat arcu et lacinia scelerisque. Fusce iaculis quis nulla et congue. Duis convallis ultricies justo, vitae rhoncus nibh tempor id. Quisque ut dolor eleifend urna faucibus aliquam. In et pulvinar dolor, eu cursus turpis. Donec quis libero commodo, pretium magna eu, porta nulla. Mauris molestie a risus non malesuada.\nIn hac habitasse platea dictumst. Morbi maximus magna at gravida vehicula. Quisque feugiat lectus et tellus gravida, iaculis dapibus diam eleifend. Quisque vitae laoreet justo. Vestibulum at auctor tellus. Curabitur in congue velit. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Sed non leo sed ipsum facilisis tempus. In ut nibh neque. Integer eu placerat sapien. In sed sagittis urna, tincidunt ultrices ipsum. Quisque efficitur in nisl vitae convallis. Sed eu varius est.\nPellentesque orci libero, volutpat vitae leo eget, egestas pharetra tellus. Fusce maximus augue nulla, vitae accumsan erat cursus eu. Integer id eros eget turpis mattis dapibus et at est. Mauris tellus lorem, porta vel eleifend vel, laoreet eget metus. Fusce convallis varius lacus, id pharetra lorem molestie eget. Quisque facilisis fermentum dui. Orci amet.\n";
	char *Test4096nnl = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam a risus gravida, rhoncus velit vitae, porttitor diam. Maecenas at sodales nibh. Sed pellentesque porttitor nisl, nec pretium libero auctor id. Curabitur vitae condimentum metus. Vestibulum sit amet dui nulla. Morbi ante nibh, egestas nec mi vel, volutpat ultricies dolor. Mauris eget risus quis neque tincidunt tristique. Duis nibh dui, fringilla pellentesque suscipit vitae, blandit nec augue. Ut ipsum ex, malesuada vitae libero in, condimentum molestie elit. Donec tempus iaculis augue ut elementum. Suspendisse vulputate magna non vehicula viverra. Pellentesque aliquet rutrum mattis. Nulla facilisi. Curabitur nulla mi, sodales ut fringilla dignissim, interdum at sapien. Lorem ipsum dolor sit amet, consectetur adipiscing elit.Ut ut magna ultrices, viverra leo non, lobortis mauris. Donec at ornare magna. Nullam quis luctus purus. Vivamus dapibus, arcu ac bibendum dignissim, metus ex maximus nisi, id iaculis felis mi et ligula. Donec vitae quam vulputate quam maximus consequat et sit amet nibh. Nam scelerisque sem id justo facilisis hendrerit. Ut nec consectetur ipsum. Sed sed lobortis tortor.Suspendisse eu accumsan mi, sit amet auctor ante. Aliquam sodales, libero sed faucibus consectetur, turpis ex maximus est, et tempus libero ipsum nec nunc. Quisque nisl mi, gravida nec ultricies ut, dignissim quis urna. Fusce arcu velit, sagittis a efficitur id, ullamcorper ut enim. Praesent vel orci interdum, viverra eros ac, rhoncus risus. Etiam cursus vehicula ligula, quis tempus purus ultrices at. Ut ultrices arcu sit amet magna sollicitudin vestibulum. Donec sit amet nulla ut sem sodales luctus. Maecenas sodales sodales nulla, nec aliquam felis aliquet nec.Etiam auctor ipsum lectus, vel faucibus nibh congue et. Pellentesque semper vestibulum lorem vitae hendrerit. Sed eu purus sit amet velit dapibus semper. Sed tempus nibh eget quam eleifend efficitur. Phasellus condimentum mauris a quam commodo, nec tempus diam mollis. Sed aliquam elit purus, a vulputate lorem bibendum sit amet. Sed quis ultrices metus. Quisque ullamcorper commodo viverra. Phasellus eu lorem et risus tincidunt malesuada. Vestibulum ullamcorper id nisl non congue. Suspendisse ullamcorper eleifend dignissim. Aliquam vulputate ut lacus et congue.Sed tincidunt, ipsum in molestie imperdiet, velit nibh ultrices tortor, sit amet dictum lectus lacus eget eros. Duis varius pretium nibh non placerat. Vestibulum feugiat placerat urna, in pharetra leo iaculis sit amet. Vestibulum ac diam ut arcu feugiat molestie quis in ex. Nunc hendrerit metus blandit eros venenatis, id rutrum urna euismod. Donec consectetur sem nibh, ac venenatis ante varius sed. Vivamus placerat dignissim ligula egestas dignissim. Curabitur vestibulum quam vitae sem venenatis sollicitudin. Pellentesque ex ligula, volutpat sed dictum non, vulputate semper nisi. Praesent consequat arcu et lacinia scelerisque. Fusce iaculis quis nulla et congue. Duis convallis ultricies justo, vitae rhoncus nibh tempor id. Quisque ut dolor eleifend urna faucibus aliquam. In et pulvinar dolor, eu cursus turpis. Donec quis libero commodo, pretium magna eu, porta nulla. Mauris molestie a risus non malesuada.In hac habitasse platea dictumst. Morbi maximus magna at gravida vehicula. Quisque feugiat lectus et tellus gravida, iaculis dapibus diam eleifend. Quisque vitae laoreet justo. Vestibulum at auctor tellus. Curabitur in congue velit. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Sed non leo sed ipsum facilisis tempus. In ut nibh neque. Integer eu placerat sapien. In sed sagittis urna, tincidunt ultrices ipsum. Quisque efficitur in nisl vitae convallis. Sed eu varius est.Pellentesque orci libero, volutpat vitae leo eget, egestas pharetra tellus. Fusce maximus augue nulla, vitae accumsan erat cursus eu. Integer id eros eget turpis mattis dapibus et at est. Mauris tellus lorem, porta vel eleifend vel, laoreet eget metus. Fusce convallis varius lacus, id pharetra lorem molestie eget. Quisque facilisis fermentum dui. Orci amet.\n";
	ft_putstr("Starting buffer test: ");
	ft_putendl(ft_itoa(BUFF_SIZE));

	make_tcmp(Test4, "4bytes.txt");
	make_tcmp(Test127, "127bytes.txt");
	make_tcmp(Test255, "255bytes.txt");
	make_tcmp(Test2048, "2048bytes.txt");
	make_tcmp(Test4096, "4096bytes.txt");
	make_tcmp(Test4096nnl, "4096nnlbytes.txt");

	wrfile("4bytes.txt");
	wrfile("127bytes.txt");
	wrfile("255bytes.txt");
	wrfile("2048bytes.txt");
	wrfile("4096bytes.txt");
	wrfile("4096nnlbytes.txt");
}