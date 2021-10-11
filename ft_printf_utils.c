int	ft_putstr_c(char *s)
{
	int	i;
	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], 1);
	return (i);
}
