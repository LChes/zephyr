/*
 * Copyright (c) 2024, Tenstorrent AI ULC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stddef.h>

#include <zephyr/kernel.h>
#include <zephyr/posix/sys/mman.h>

#include <zephyr/kernel/mm/demand_paging.h>

int mlock(const void *addr, size_t len)
{
	void *const _addr = (void *)addr;

	k_mem_pin(_addr, len);

	return 0;
}

int munlock(const void *addr, size_t len)
{
	void *const _addr = (void *)addr;

	k_mem_unpin(_addr, len);

	return 0;
}
