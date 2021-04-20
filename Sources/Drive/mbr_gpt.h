#pragma once

#include <WinIoCtl.h>
#include <Ntddscsi.h>
#include <guiddef.h>
#include <Windows.h>

#include <cstdint>

#define LOGICAL_SECTOR_SIZE				0x200

#define kNominalMediaRotRateWordIndex	217

#define PARTITION_ENTRY_UNUSED          0x00
#define PARTITION_FAT_12                0x01
#define PARTITION_XENIX_1               0x02
#define PARTITION_XENIX_2               0x03
#define PARTITION_FAT_16                0x04
#define PARTITION_EXTENDED              0x05
#define PARTITION_HUGE                  0x06
#define PARTITION_IFS                   0x07
#define PARTITION_OS2BOOTMGR            0x0A
#define PARTITION_FAT32                 0x0B
#define PARTITION_FAT32_XINT13          0x0C
#define PARTITION_XINT13                0x0E
#define PARTITION_XINT13_EXTENDED       0x0F
#define PARTITION_PREP                  0x41
#define PARTITION_LDM                   0x42
#define PARTITION_UNIX                  0x63
#define VALID_NTFT                      0xC0
#define PARTITION_NTFT                  0x80
#define PARTITION_EDI_HEADER            0xEE

// General
const GUID PARTITION_ENTRY_UNUSED_GUID = { 0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // 00000000-0000-0000-0000-000000000000
const GUID PARTITION_MBR_SCHEME_GUID = { 0x024DEE41, 0x33E7, 0x11D3, 0x9D, 0x69, 0x00, 0x08, 0xC7, 0x81, 0xF3, 0x9F }; //024DEE41-33E7-11D3-9D69-0008C781F39F
const GUID PARTITION_SYSTEM_GUID = { 0xc12a7328, 0xf81f, 0x11d2, 0xba, 0x4b, 0x00, 0xa0, 0xc9, 0x3e, 0xc9, 0x3b }; //C12A7328-F81F-11D2-BA4B-00A0C93EC93B
const GUID PARTITION_BIOS_BOOT_GUID = { 0x21686148, 0x6449, 0x6E6F, 0x74, 0x4E, 0x65, 0x65, 0x64, 0x45, 0x46, 0x49 }; //21686148-6449-6E6F-744E-656564454649

// Windows
const GUID PARTITION_MSFT_RESERVED_GUID = { 0xe3c9e316, 0x0b5c, 0x4db8, 0x81, 0x7d, 0xf9, 0x2d, 0xf0, 0x02, 0x15, 0xae }; //E3C9E316-0B5C-4DB8-817D-F92DF00215AE
const GUID PARTITION_BASIC_DATA_GUID = { 0xebd0a0a2, 0xb9e5, 0x4433, 0x87, 0xc0, 0x68, 0xb6, 0xb7, 0x26, 0x99, 0xc7 }; //EBD0A0A2-B9E5-4433-87C0-68B6B72699C7 (also used for Linux data)
const GUID PARTITION_LDM_METADATA_GUID = { 0x5808c8aa, 0x7e8f, 0x42e0, 0x85, 0xd2, 0xe1, 0xe9, 0x04, 0x34, 0xcf, 0xb3 }; //5808C8AA-7E8F-42E0-85D2-E1E90434CFB3
const GUID PARTITION_LDM_DATA_GUID = { 0xaf9b60a0, 0x1431, 0x4f62, 0xbc, 0x68, 0x33, 0x11, 0x71, 0x4a, 0x69, 0xad }; //AF9B60A0-1431-4F62-BC68-3311714A69AD
const GUID PARTITION_MSFT_RECOVERY_GUID = { 0xde94bba4, 0x06d1, 0x4d40, 0xa1, 0x6a, 0xbf, 0xd5, 0x01, 0x79, 0xd6, 0xac }; //DE94BBA4-06D1-4D40-A16A-BFD50179D6AC
const GUID PARTITION_IBM_GPFS_GUID = { 0x37AFFC90, 0xEF7D, 0x4E96, 0x91, 0xC3, 0x2D, 0x7A, 0xE0, 0x55, 0xB1, 0x74 }; //37AFFC90-EF7D-4E96-91C3-2D7AE055B174

// HP-UX
const GUID PARTITION_HPUX_DATA_GUID = { 0x75894C1E, 0x3AEB, 0x11D3, 0xB7, 0xC1, 0x7B, 0x03, 0xA0, 0x00, 0x00, 0x00 }; //75894C1E-3AEB-11D3-B7C1-7B03A0000000
const GUID PARTITION_HPUX_SERVICE_GUID = { 0xE2A1E728, 0x32E3, 0x11D6, 0xA6, 0x82, 0x7B, 0x03, 0xA0, 0x00, 0x00, 0x00 }; //E2A1E728-32E3-11D6-A682-7B03A0000000

// Linux
const GUID PARTITION_LINUX_DATA_GUID = { 0xEBD0A0A2, 0xB9E5, 0x4433, 0x87, 0xC0, 0x68, 0xB6, 0xB7, 0x26, 0x99, 0xC7 }; //EBD0A0A2-B9E5-4433-87C0-68B6B72699C7 (also used for Windows basic data)
const GUID PARTITION_LINUX_RAID_GUID = { 0xA19D880F, 0x05FC, 0x4D3B, 0xA0, 0x06, 0x74, 0x3F, 0x0F, 0x84, 0x91, 0x1E }; //A19D880F-05FC-4D3B-A006-743F0F84911E
const GUID PARTITION_LINUX_SWAP_GUID = { 0x0657FD6D, 0xA4AB, 0x43C4, 0x84, 0xE5, 0x09, 0x33, 0xC8, 0x4B, 0x4F, 0x4F }; //0657FD6D-A4AB-43C4-84E5-0933C84B4F4F
const GUID PARTITION_LINUX_LVM_GUID = { 0xE6D6D379, 0xF507, 0x44C2, 0xA2, 0x3C, 0x23, 0x8F, 0x2A, 0x3D, 0xF9, 0x28 }; //E6D6D379-F507-44C2-A23C-238F2A3DF928
const GUID PARTITION_LINUX_RESERVED_GUID = { 0x8DA63339, 0x0007, 0x60C0, 0xC4, 0x36, 0x08, 0x3A, 0xC8, 0x23, 0x09, 0x08 }; //8DA63339-0007-60C0-C436-083AC8230908

// FreeBSD
const GUID PARTITION_FREEBSD_BOOT_GUID = { 0x83BD6B9D, 0x7F41, 0x11DC, 0xBE, 0x0B, 0x00, 0x15, 0x60, 0xB8, 0x4F, 0x0F }; //83BD6B9D-7F41-11DC-BE0B-001560B84F0F
const GUID PARTITION_FREEBSD_DATA_GUID = { 0x516E7CB4, 0x6ECF, 0x11D6, 0x8F, 0xF8, 0x00, 0x02, 0x2D, 0x09, 0x71, 0x2B }; //516E7CB4-6ECF-11D6-8FF8-00022D09712B
const GUID PARTITION_FREEBSD_SWAP_GUID = { 0x516E7CB5, 0x6ECF, 0x11D6, 0x8F, 0xF8, 0x00, 0x02, 0x2D, 0x09, 0x71, 0x2B }; //516E7CB5-6ECF-11D6-8FF8-00022D09712B
const GUID PARTITION_FREEBSD_UFS_GUID = { 0x516E7CB6, 0x6ECF, 0x11D6, 0x8F, 0xF8, 0x00, 0x02, 0x2D, 0x09, 0x71, 0x2B }; //516E7CB6-6ECF-11D6-8FF8-00022D09712B
const GUID PARTITION_FREEBSD_VINUM_VM_GUID = { 0x516E7CB8, 0x6ECF, 0x11D6, 0x8F, 0xF8, 0x00, 0x02, 0x2D, 0x09, 0x71, 0x2B }; //516E7CB8-6ECF-11D6-8FF8-00022D09712B
const GUID PARTITION_FREEBSD_ZFS_GUID = { 0x516E7CBA, 0x6ECF, 0x11D6, 0x8F, 0xF8, 0x00, 0x02, 0x2D, 0x09, 0x71, 0x2B }; //516E7CBA-6ECF-11D6-8FF8-00022D09712B

// Mac OS X
const GUID PARTITION_APPLE_HFSP_GUID = { 0x48465300, 0x0000, 0x11AA, 0xAA, 0x11, 0x00, 0x30, 0x65, 0x43, 0xEC, 0xAC }; //48465300-0000-11AA-AA11-00306543ECAC
const GUID PARTITION_APPLE_UFS_GUID = { 0x55465300, 0x0000, 0x11AA, 0xAA, 0x11, 0x00, 0x30, 0x65, 0x43, 0xEC, 0xAC }; //55465300-0000-11AA-AA11-00306543ECAC
const GUID PARTITION_APPLE_ZFS_GUID = { 0x6A898CC3, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A898CC3-1DD2-11B2-99A6-080020736631 (from Solaris /usr)
const GUID PARTITION_APPLE_RAID_GUID = { 0x52414944, 0x0000, 0x11AA, 0xAA, 0x11, 0x00, 0x30, 0x65, 0x43, 0xEC, 0xAC }; //52414944-0000-11AA-AA11-00306543ECAC
const GUID PARTITION_APPLE_RAID_OFFLINE_GUID = { 0x52414944, 0x5F4F, 0x11AA, 0xAA, 0x11, 0x00, 0x30, 0x65, 0x43, 0xEC, 0xAC }; //52414944-5F4F-11AA-AA11-00306543ECAC
const GUID PARTITION_APPLE_BOOT_GUID = { 0x426F6F74, 0x0000, 0x11AA, 0xAA, 0x11, 0x00, 0x30, 0x65, 0x43, 0xEC, 0xAC }; //426F6F74-0000-11AA-AA11-00306543ECAC
const GUID PARTITION_APPLE_LABEL_GUID = { 0x4C616265, 0x6C00, 0x11AA, 0xAA, 0x11, 0x00, 0x30, 0x65, 0x43, 0xEC, 0xAC }; //4C616265-6C00-11AA-AA11-00306543ECAC
const GUID PARTITION_APPLE_TV_RECOVERY_GUID = { 0x5265636F, 0x7665, 0x11AA, 0xAA, 0x11, 0x00, 0x30, 0x65, 0x43, 0xEC, 0xAC }; //5265636F-7665-11AA-AA11-00306543ECAC

// Solaris
const GUID PARTITION_SOLARIS_BOOT_GUID = { 0x6A82CB45, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A82CB45-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_ROOT_GUID = { 0x6A85CF4D, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A85CF4D-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_SWAP_GUID = { 0x6A87C46F, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A87C46F-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_BACKUP_GUID = { 0x6A8B642B, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A8B642B-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_USR_GUID = { 0x6A898CC3, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A898CC3-1DD2-11B2-99A6-080020736631 (also used for Mac OS X ZFS)
const GUID PARTITION_SOLARIS_VAR_GUID = { 0x6A8EF2E9, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A8EF2E9-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_HOME_GUID = { 0x6A90BA39, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A90BA39-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_ALTERNATE_GUID = { 0x6A9283A5, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A9283A5-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_RESERVED_1_GUID = { 0x6A945A3B, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A945A3B-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_RESERVED_2_GUID = { 0x6A9630D1, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A9630D1-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_RESERVED_3_GUID = { 0x6A980767, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A980767-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_RESERVED_4_GUID = { 0x6A96237F, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A96237F-1DD2-11B2-99A6-080020736631
const GUID PARTITION_SOLARIS_RESERVED_5_GUID = { 0x6A8D2AC7, 0x1DD2, 0x11B2, 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 }; //6A8D2AC7-1DD2-11B2-99A6-080020736631

// NetBSD
const GUID PARTITION_NETBSD_SWAP_GUID = { 0x49F48D32, 0xB10E, 0x11DC, 0xB9, 0x9B, 0x00, 0x19, 0xD1, 0x87, 0x96, 0x48 }; //49F48D32-B10E-11DC-B99B-0019D1879648
const GUID PARTITION_NETBSD_FFS_GUID = { 0x49F48D5A, 0xB10E, 0x11DC, 0xB9, 0x9B, 0x00, 0x19, 0xD1, 0x87, 0x96, 0x48 }; //49F48D5A-B10E-11DC-B99B-0019D1879648
const GUID PARTITION_NETBSD_LFS_GUID = { 0x49F48D82, 0xB10E, 0x11DC, 0xB9, 0x9B, 0x00, 0x19, 0xD1, 0x87, 0x96, 0x48 }; //49F48D82-B10E-11DC-B99B-0019D1879648
const GUID PARTITION_NETBSD_RAID_GUID = { 0x49F48DAA, 0xB10E, 0x11DC, 0xB9, 0x9B, 0x00, 0x19, 0xD1, 0x87, 0x96, 0x48 }; //49F48DAA-B10E-11DC-B99B-0019D1879648
const GUID PARTITION_NETBSD_CONCATENATED_GUID = { 0x2DB519C4, 0xB10F, 0x11DC, 0xB9, 0x9B, 0x00, 0x19, 0xD1, 0x87, 0x96, 0x48 }; //2DB519C4-B10F-11DC-B99B-0019D1879648
const GUID PARTITION_NETBSD_ENCRYPTED_GUID = { 0x2DB519EC, 0xB10F, 0x11DC, 0xB9, 0x9B, 0x00, 0x19, 0xD1, 0x87, 0x96, 0x48 }; //2DB519EC-B10F-11DC-B99B-0019D1879648

// ChromeOS
const GUID PARTITION_CHROME_KERNEL_GUID = { 0xFE3A2A5D, 0x4F32, 0x41A7, 0xB7, 0x25, 0xAC, 0xCC, 0x32, 0x85, 0xA3, 0x09 }; //FE3A2A5D-4F32-41A7-B725-ACCC3285A309
const GUID PARTITION_CHROME_ROOTFS_GUID = { 0x3CB8E202, 0x3B7E, 0x47DD, 0x8A, 0x3C, 0x7F, 0xF2, 0xA1, 0x3C, 0xFC, 0xEC }; //3CB8E202-3B7E-47DD-8A3C-7FF2A13CFCEC
const GUID PARTITION_CHROME_RESERVED_GUID = { 0x2E0A753D, 0x9E48, 0x43B0, 0x83, 0x37, 0xB1, 0x51, 0x92, 0xCB, 0x1B, 0x5E }; //2E0A753D-9E48-43B0-8337-B15192CB1B5E

#pragma pack(push, 1)

struct chs {
	uint8_t head;
	uint8_t sector;
	uint8_t cylinder;
};

struct mbr_partition {
	uint8_t status;
	struct chs first_sector;
	uint8_t partition_type;
	struct chs last_sector;
	uint32_t first_sector_lba;
	uint32_t sectors;
};

typedef struct {
	char code[440];
	uint32_t disk_signature;
	uint16_t reserved;
	struct mbr_partition partition[4];
	uint16_t mbr_signature;
} MBR, * PMBR;

typedef struct {
	char unused[446];
	struct mbr_partition partition[4];
	uint16_t mbr_signature;
} EBR, * PEBR;

typedef uint64_t EFI_LBA;

typedef struct {
	char magic[8];
	uint16_t revision_low;
	uint16_t revision_high;
	uint32_t header_size;
	uint32_t header_crc32;
	uint32_t reserved1;
	uint64_t current_lba;
	uint64_t backup_lba;
	uint64_t first_usable_lba;
	uint64_t last_usable_lba;
	GUID	 disk_guid;
	uint64_t partition_entry_lba;
	uint32_t num_partition_entries;
	uint32_t sizeof_partition_entry;
	uint32_t partition_entry_array_crc32;
	uint8_t reserved2[420];
}  GPT_HEADER, * PGPT_HEADER;

typedef struct {
	GUID		PartitionTypeGUID;
	GUID		UniquePartitionGUID;
	EFI_LBA		StartingLBA;
	EFI_LBA		EndingLBA;
	uint64_t	Attributes;
	WCHAR		PartitionName[36];
} GPT_PARTITION_ENTRY, * PGPT_PARTITION_ENTRY;

struct ATAIdentifyDeviceQuery
{
	ATA_PASS_THROUGH_EX header;
	WORD data[256];
};

#pragma pack(pop)