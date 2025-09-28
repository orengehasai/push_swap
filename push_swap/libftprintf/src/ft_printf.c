/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:53:52 by takenakatak       #+#    #+#             */
/*   Updated: 2025/05/05 11:44:13 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
va_list <変数名>;
va_start(<va_list 変数>, <最後の固定引数名>);
<取り出した引数を格納する変数> = va_arg(<va_list 変数>, <引数の型>);
va_copy(<コピー先 va_list 変数>, <コピー元 va_list 変数>);
va_end(<va_list 変数>);

char および short int 型の値は、可変引数リストに渡される際に自動的に int 型に**昇格（プロモート）**されます。
渡される引数の個数を超える回数va_arg()で取得した場合未定義動作（適当な数値を取ってくる）。

「引数の数が違うよ」「型が違うよ」といった警告を見たことがあるとすれば、それはこのコンパイラの静的解析機能のおかげです
*/
/*
使用
返り値は出力した文字数（指定子の型によらず、変数の値が文字列に埋め込まれる？)
*/
/*手順
1 文字列に%が来るまで走査
2 ％の後に所定の文字（列）が続くか判定＝文字列が正しい書式か判定
3 ２が真の場合、%の個数(%%除く）と可変長引数の個数が等しいか判定　※コンパイラやツールの機能らしいため不要、未定義動作
4 ３が真の場合、指定子と引数の型が等しいか判定　（３と同時判定でも良いかも）※コンパイラやツールの機能らしいため不要、未定義動作
*/
//%pは最上位から連続する0は全部省略。ただし0のみの場合は0を１つ出力。

static char	specifier(const char **str, int *output_len)
{
	int		i;
	char	*charset;

	i = 0;
	charset = "cspdiuxX%";
	while (**str != '%' && **str)
	{
		write(1, *str, 1);
		(*str)++;
		(*output_len)++;
	}
	if (!**str)
		return (0);
	(*str)++;
	while (charset[i])
	{
		if (**str == charset[i])
		{
			(*str)++;
			return (charset[i]);
		}
		i++;
	}
	return (-1);
}

static int	dispatch_specifier(const char *str, va_list args)
{
	char	spe;
	int		res;

	res = 0;
	while (*str)
	{
		spe = specifier(&str, &res);
		if (spe == 'c')
			res += print_c((char)va_arg(args, int));
		else if (spe == 's')
			res += print_s(va_arg(args, char *));
		else if (spe == 'p')
			res += print_p(va_arg(args, void *));
		else if (spe == 'd' || spe == 'i')
			res += print_di(va_arg(args, int));
		else if (spe == 'u')
			res += print_u(va_arg(args, unsigned int));
		else if (spe == 'x' || spe == 'X')
			res += print_x(va_arg(args, int), spe);
		else if (spe == '%')
			res += write(1, "%", 1);
		else if (spe == -1)
			return (-1);
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		res;

	va_start(args, str);
	res = dispatch_specifier(str, args);
	va_end(args);
	return (res);
}

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
// 	int d = 100;
// 	int res = ft_printf("aask%dp;asf%%%r21%d",d);
// 	ft_printf("\n%d",res);
// 	//printf("%d\n",printf("%s",d));
// 	return 0;
// }
