#include "main.h"
/**
 * verify_exe_link_func - Ensures that a file is in ELF format.
 * @ident_err: Ptr to array holding file's ELF identification magic numbers.
 *
 * Description: Exits with code 98 if the file is not an ELF.
 */
void verify_exe_link_func(unsigned char *ident_err)
{
	int my_pos = 0;

	while (my_pos < 4)
	{
		if (ident_err[my_pos] != 127 &&
				ident_err[my_pos] != 'E' &&
				ident_err[my_pos] != 'L' &&
				ident_err[my_pos] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		my_pos++;
	}
}
/**
 * show_magic - Displays the ELF magic numbers.
 * @ident_err: Ptr to array holding the ELF magic numbers.
 * Description: Magic numbers are printed with spaces separating them.
 */
void show_magic(unsigned char *ident_err)
{
	int my_pos = 0;

	printf("  Magic:   ");
	while (my_pos < EI_NIDENT)
	{
		printf("%02x", ident_err[my_pos]);
		if (my_pos == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
		my_pos++;
	}
}
/**
 * output_class - Outputs the class of an ELF header.
 * @ident_err: Ptr to array holding ELF class info.
 */
void output_class(unsigned char *ident_err)
{
	printf("  Class:                             ");
	if (ident_err[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (ident_err[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (ident_err[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", ident_err[EI_CLASS]);
}
/**
 * display_data - Outputs the data encoding of an ELF header.
 * @ident_err: Ptr to array holding ELF data encoding info.
 */
void display_data(unsigned char *ident_err)
{
	printf("  Data:                              ");
	if (ident_err[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else if (ident_err[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (ident_err[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", ident_err[EI_CLASS]);
}
/**
 * display_version - Outputs the version of an ELF header.
 * @ident_err: Ptr to array holding ELF version info.
 */
void display_version(unsigned char *ident_err)
{
	printf("  Version:                           %d", ident_err[EI_VERSION]);
	if (ident_err[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}
/**
 * output_osabi - Outputs the OS/ABI of an ELF header.
 * @ident_err: Ptr to array holding ELF OS/ABI info.
 */
void output_osabi(unsigned char *ident_err)
{
	printf("  OS/ABI:                            ");
	switch (ident_err[EI_OSABI])
	{
		case ELFOSABI_NONE:
			{
				printf("UNIX - System V\n");
				break;
			}
		case ELFOSABI_HPUX:
			{
				printf("UNIX - HP-UX\n");
				break;
			}
		case ELFOSABI_NETBSD:
			{
				printf("UNIX - NetBSD\n");
				break;
			}
		case ELFOSABI_LINUX:
			{
				printf("UNIX - Linux\n");
				break;
			}
		case ELFOSABI_SOLARIS:
			{
				printf("UNIX - Solaris\n");
				break;
			}
		case ELFOSABI_IRIX:
			{
				printf("UNIX - IRIX\n");
				break;
			}
		case ELFOSABI_FREEBSD:
			{
				printf("UNIX - FreeBSD\n");
				break;
			}
		case ELFOSABI_TRU64:
			{
				printf("UNIX - TRU64\n");
				break;
			}
		case ELFOSABI_ARM:
			{
				printf("ARM\n");
				break;
			}
		case ELFOSABI_STANDALONE:
			{
				printf("Standalone App\n");
				break;
			}
		default:
			{
				printf("<unknown: %x>\n", ident_err[EI_OSABI]);
				break;
			}
	}
}
/**
 * show_abi - Outputs the ABI version of an ELF header.
 * @ident_err: Ptr to array holding ELF ABI version info.
 */
void show_abi(unsigned char *ident_err)
{
	printf("  ABI Version:                       %d\n", ident_err[EI_ABIVERSION]);
}
/**
 * display_type - Outputs the type of an ELF header.
 * @err_type: ELF header type.
 * @ident_err: Ptr to array holding ELF type info.
 */
void display_type(unsigned int err_type, unsigned char *ident_err)
{
	if (ident_err[EI_DATA] == ELFDATA2MSB)
		err_type >>= 8;
	printf("  Type:                              ");
	if (err_type == ET_NONE)
		printf("NONE (None)\n");
	else if (err_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (err_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (err_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (err_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", err_type);
}
/**
 * show_entry - Outputs the entry point of an ELF header.
 * @err_entry: ELF header entry point.
 * @ident_err: Ptr to array holding ELF entry info.
 */
void show_entry(unsigned long int err_entry, unsigned char *ident_err)
{
	printf("  Entry point address:               ");
	if (ident_err[EI_DATA] == ELFDATA2MSB)
	{
		err_entry = __builtin_bswap64(err_entry);
	}
	if (ident_err[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)err_entry);
	else
		printf("%#lx\n", err_entry);
}
/**
 * exit_exe_link_func - Closes an ELF file descriptor.
 * @elf: ELF file descriptor.
 * Description: Exits with code 98 if closing the file fails.
 */
void exit_exe_link_func(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
/**
 * main - Displays information in the ELF header of a file.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Description: Exits with code 98 if the file is not an ELF.
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int open_status, read_status;

	open_status = open(argv[1], O_RDONLY);
	if (open_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		exit_exe_link_func(open_status);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read_status = read(open_status, header, sizeof(Elf64_Ehdr));
	if (read_status == -1)
	{
		free(header);
		exit_exe_link_func(open_status);
		dprintf(STDERR_FILENO, "Error: '%s': No such file\n", argv[1]);
		exit(98);
	}
	verify_exe_link_func((*header).e_ident);
	printf("ELF Header:\n");
	show_magic((*header).e_ident);
	output_class((*header).e_ident);
	display_data((*header).e_ident);
	display_version((*header).e_ident);
	output_osabi((*header).e_ident);
	show_abi((*header).e_ident);
	display_type((*header).e_type, (*header).e_ident);
	show_entry((*header).e_entry, (*header).e_ident);
	free(header);
	exit_exe_link_func(open_status);
	return (0);
}
