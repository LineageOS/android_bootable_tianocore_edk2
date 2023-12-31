/** @file
  ACPI Memory System Resource Partitioning And Monitoring (MPAM)
  as specified in ARM spec DEN0065

  Copyright (c) 2022, NVIDIA CORPORATION. All rights reserved.
  Copyright (c) 2022, ARM Limited. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _MPAM_H_
#define _MPAM_H_

///
/// Location Types
///
#define EFI_ACPI_MPAM_LOCATION_TYPE_PROCESSOR_CACHE  0x00
#define EFI_ACPI_MPAM_LOCATION_TYPE_MEMORY           0x01
#define EFI_ACPI_MPAM_LOCATION_TYPE_SMMU             0x02
#define EFI_ACPI_MPAM_LOCATION_TYPE_MEMORY_CACHE     0x03
#define EFI_ACPI_MPAM_LOCATION_TYPE_ACPI_DEVICE      0x04

///
/// Interrupt Flags
///
#define EFI_ACPI_MPAM_LEVEL_TRIG_INTERRUPT_MODE     0x0
#define EFI_ACPI_MPAM_EDGE_TRIG_INTERRUPT_MODE      0x1
#define EFI_ACPI_MPAM_WIRED_INTERRUPT_TYPE          0x0
#define EFI_ACPI_MPAM_PROC_INTR_AFF_TYPE            0x0
#define EFI_ACPI_MPAM_PROC_CONTAINER_INTR_AFF_TYPE  0x8
#define EFI_ACPI_MPAM_AFFINITY_VALID                0x10

#pragma pack(1)

///
/// Memory System Resource Partitioning and Monitoring Table (MPAM)
///
typedef struct {
  EFI_ACPI_DESCRIPTION_HEADER    Header;
} EFI_ACPI_6_4_MEMORY_SYSTEM_RESOURCE_PARTITIONING_MONITORING_TABLE_HEADER;

///
/// MPAM Revision (as defined in ACPI 6.4 spec.)
///
#define EFI_ACPI_6_4_MEMORY_SYSTEM_RESOURCE_PARTITIONING_MONITORING_TABLE_REVISION  0x01

///
/// Memory System Controller Node Structure
///

typedef struct {
  UINT16    Length;
  UINT16    Reserved;
  UINT32    Identifier;
  UINT64    BaseAddress;
  UINT32    MmioSize;
  UINT32    OverflowInterrupt;
  UINT32    OverflowInterruptFlags;
  UINT32    Reserved1;
  UINT32    OverflowInterruptAff;
  UINT32    ErrorInterrupt;
  UINT32    ErrorInterruptFlags;
  UINT32    Reserved2;
  UINT32    ErrorInterruptAff;
  UINT32    MaxNRdyUsec;
  UINT64    LinkedDeviceHwId;
  UINT32    LinkedDeviceInstanceHwId;
  UINT32    NumResourceNodes;
} EFI_ACPI_6_4_MPAM_MSC_NODE;

///
/// Resource Node Structure
///

typedef struct {
  UINT32    Identifier;
  UINT8     RisIndex;
  UINT16    Reserved1;
  UINT8     LocatorType;
  UINT64    Locator1;
  UINT32    Locator2;
  UINT32    NumFuncDep;
} EFI_ACPI_6_4_MPAM_RESOURCE_NODE;

///
/// Functional Dependency Structure
///

typedef struct {
  UINT32    Producer;
  UINT32    Reserved1;
} EFI_ACPI_6_4_MPAM_FUNC_DEP_NODE;

#pragma pack()

#endif
