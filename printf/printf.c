#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_tag	tag;
	char	c;
	char	*s;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
//			if (*format == 'c')
//			{
//				c = va_arg(ap, int);
//				printf("%c\n", c);
//			}
//			if (*format == 's')
//			{
//				s = va_arg(ap, char*);
//				ft_putstr_fd(s, 1);
//			}
			ft_memset(&tag, 0, sizeof(t_tag));
			handle_flag(&format, ap, &tag);
			handle_type(&format, ap, &tag);
		}
		ft_putchar_fd(*format, 1);
		format ++;
	}
	va_end(ap);
}

int	main(void)
{
	char c = 'a';
	char *s = "abcd";
	
	ft_printf("character : %c\t string : %s \n", c, s);
//	ft_printf("string : %s\n", s);
//	ft_printf("decimal(d) : %d\n", d);
//	ft_printf("decimal(i) : %i\n", d);

}
