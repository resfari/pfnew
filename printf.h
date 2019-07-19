/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:02:21 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/19 17:02:21 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <inttypes.h>
# include <stdint.h>
# include <limits.h>
# include <float.h>
# include <math.h>

typedef	struct			s_pf
{
	int					**mass;
	char				*str;
	char				**procent;
	int					width;
	int					length;
	int					count;
	int					i;
	int					j;
	int					value;
}						t_pf;

typedef	struct			s_flags
{
	int					flagplus;
	int					flagminus;
	int					flagspace;
	int					flaglattice;
	int					accuracy;
	int					width;
	int					nol;
	int					l;
	int					e;
	int					m;
	int					start;
	int					lastpos;
	int					masssize;
	int					*final;
	int					finalsize;
	int					edinica;
	int					value;
	int					sl;
	int					sll;
	int					sh;
	int					shh;
	int					sign;
	int					len;
	int					acc_x;
	int					i;
	int					exp;
	int					itsf;
	int					puted;
	int					perehod_in_acc;
	int					f;
	int					accspec;
}						t_fl;

typedef	struct			s_ar
{
	int					*mass;
	int					size;
	int					firsth;
	int					count;
	int					exp;
}						t_ar;

typedef	struct			s_summ
{
	int					*mass;
	int					size;
	int					numbnol;
	int					exp;
	int					et_size;
	int					*final1;
	int					*final2;
	int					edinica;
}						t_summ;

typedef	struct			s_final
{
	int					*after;
	int					*before;
	int					perenos;
	int					perenos2;
	int					*acc;
	int					i;
	int					count;
}						t_final;

typedef	struct			s_mean
{
	int					i;
	int					j;
	int					size;
	int					help;
	int					mod;
	int					*new;
	int					exp;
	int					numbnol;
	int					equal;
}						t_mean;

typedef	struct			s_plus
{
	int					i;
	int					*res;
	int					mod;
	int					size;
	int					equal;
}						t_plus;

int						ft_read_arg(va_list list, t_pf *pf);
int						ft_conclusionstr(t_fl *fl, char *arg, t_pf *pf);
void					ft_flagsinit(t_fl *fl);
int						ft_accuracy(char *str, t_fl *fl);
int						ft_width(char *str, t_fl *fl);
int						ft_flags(char *str, t_fl *fl);
int						ft_conclusionint(t_fl *fl, int arg, int sign);
int						ft_conclusionchar(t_fl *fl, int arg, t_pf *pf);
int						ft_checkplus(t_fl *fl);
void					ft_writenolspace(int start, int end, int k);
int						ft_concfloat(va_list list, t_fl *fl1);
int						ft_conclusionfloat(t_fl *fl1, float x);
void					ft_putld(long n, int *p);
int						*ft_calcsumm(int *first, int *second, int masssize);
int						*ft_calcmulti(int power);
int						*ft_calcmultifive(int *mass, int masssize);
t_ar					*ft_intmulti();
void					ft_zero(int *mass, int masssize);
t_summ					*ft_fivemulti(int exp, t_summ *summ, int masssize);
t_summ					*ft_summastart(int exp, t_summ *summ, int masssize);
int						*ft_copymass(int *mass, int size);
int						ft_check_result(int *mass);
t_summ					*ft_delete_two(t_summ *summ, int masssize);
int						*ft_calcsumm_two(int *first, int *second,
		t_summ *summ, int masssize);
t_summ					*ft_first_mean_two(int exp, t_summ *summ, int masssize);
int						*ft_reverse(int *mass, int count,
		int size, int masssize);
void					ft_calc_mantissa_over(int *man, t_fl *fl);
int						ft_lorllcheck(char *str, t_fl *fl);
int						ft_conclusiondouble(t_fl *fl1, double x);
int						ft_conclusionlongdouble(t_fl *fl1, long double x);
void					ft_accuracy_in_work(t_fl *fl, t_summ *summ);
void					ft_calcsumm_final(int *first, int *second, int masssize,
		t_final *final);
int						ft_conclusionproc(t_fl *fl, t_pf *pf);
int						ft_accuracy_str(char *str, t_fl *fl);
int						ft_lllhhh(char *str, t_fl *fl);
char					*ft_ltoa(intmax_t n);
char					*ft_utoa(uintmax_t n);
int						ft_concchar(char *s, va_list list, t_pf *pf);
int						ft_concstr(char *s, va_list list, t_pf *pf);
int						ft_concproc(char *s, t_pf *pf);
int						ft_concint(char *s, va_list list, char c, t_pf *pf);
int						ft_concu(char *s, va_list list, char c, t_pf *pf);
int						ft_concpointer(char *s, va_list list, t_pf *pf);
int						ft_concx(char *s, va_list list, char c, t_pf *pf);
int						ft_conco(char *s, va_list list, char c, t_pf *pf);
void					ft_size_width_check_flags(t_fl *fl);
int						ft_int_sign_display(t_fl *fl, t_pf *pf);
int						ft_int_width_display_minus(t_fl *fl, t_pf *pf);
void					ft_int_accuracy_display(int acc, t_fl *fl, t_pf *pf);
void					ft_octo_norm(char *str, t_pf *pf, int len);
void					ft_pf_write_norm(t_pf *pf, t_fl *fl, int norm);
void					ft_free_fl1(t_fl *fl);
void					ft_hex_norm(t_fl *fl, t_pf *pf, int norm);
int						ft_uint_width_display_offminus(int acc,
		int len, t_fl *fl, t_pf *pf);
int						ft_uint_width_display_minus(t_fl *fl, t_pf *pf);
int						ft_check_str(char *str);
void					ft_float_write(t_fl *fl, int norm);
int						ft_check_exp(char *str, t_fl *fl);
char					*ft_checkbindouble(t_fl *fl1, double x);
char					*ft_checkbinfloat(t_fl *fl1, float x);
char					*ft_checkbinlongdouble(t_fl *fl1, long double x);
int						*ft_check_mantissa(char *str, t_fl *fl);
int						ft_check_sign(char c, t_fl *fl);
void					ft_calc_mantissa_before(int *man, t_fl *fl);
void					ft_create_massive_for_accuracy(t_final *fin,
		t_fl *fl, t_summ *summ);
int						ft_check_infinity(t_fl *fl);
int						ft_check_nan(t_fl *fl);
void					ft_sign_put(t_fl *fl);
int						ft_check_max(char *str, int count, t_fl *fl);
int						ft_check_elements(int *mass, t_fl *fl);
int						ft_concdouble(char *s, va_list list, t_pf *pf);
void					ft_mantissa_p4(t_fl *fl);
void					ft_hex_display_norm(t_fl *fl, char *str, int i);

#endif
