#ifndef _LIB_KSTRTOX_H
#define _LIB_KSTRTOX_H

#define KSTRTOX_OVERFLOW	(1U << 31)
const char *_parse_integer_fixup_radix(const char *s, unsigned int *base);
unsigned int _parse_integer(const char *s, unsigned int base, unsigned long long *res);

int __must_check _kstrtoul(const char *s, unsigned int base, unsigned long *res);
int __must_check _kstrtol(const char *s, unsigned int base, long *res);

int __must_check kstrtoull(const char *s, unsigned int base, unsigned long long *res);
int __must_check kstrtoll(const char *s, unsigned int base, long long *res);

static inline int __must_check kstrtoul(const char *s, unsigned int base, unsigned long *res)
{
        /*
         * We want to shortcut function call, but
         * __builtin_types_compatible_p(unsigned long, unsigned long long) = 0.
         */
        if (sizeof(unsigned long) == sizeof(unsigned long long) &&
            __alignof__(unsigned long) == __alignof__(unsigned long long))
                return kstrtoull(s, base, (unsigned long long *)res);
        else
                return _kstrtoul(s, base, res);
}

static inline int __must_check kstrtol(const char *s, unsigned int base, long *res)
{
        /*
         * We want to shortcut function call, but
         * __builtin_types_compatible_p(long, long long) = 0.
         */
        if (sizeof(long) == sizeof(long long) &&
            __alignof__(long) == __alignof__(long long))
                return kstrtoll(s, base, (long long *)res);
        else
                return _kstrtol(s, base, res);
}

static inline char _tolower(const char c)
{
        return c | 0x20;
}

#endif
