/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahbanko <sarahbanko@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:09:16 by sarahbanko        #+#    #+#             */
/*   Updated: 2026/08/11 17:05:04 by sarahbanko       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

void bench_disorder(double disorder)
{
    int integer_part;
    int decimal_part;
    int rounded_value;

    rounded_value = (int)((disorder * 100) * 100 + 0.5); 
    integer_part = rounded_value / 100; // para pegarmos as duas casas antes da virgula
    decimal_part = rounded_value % 100; // para pegarmos as duas casas depois da virgula
    write(2, "disorder: ", 10);
    ft_putnbr_fd(integer_part, 2);
    write(2, ".", 1);
    if (decimal_part < 10)
        write(2, "0", 1);
    ft_putnbr_fd(decimal_part, 2);
    write(2, "%", 1);
    write(2, "\n", 1);
}

void bench_strategy(t_strategy strat, double disorder) // receber a disorder que foi calculada no começo, pois o bench chama depois q ja executou
{
    write(2, "strategy: ", 10);
    if (strat == SIMPLE) // conferir essa parte, pois precisamos da strategia q prevaleceu
        write(2, "Simple / O(n^2)", 15);
    else if (strat == MEDIUM)
        write(2, "Medium / O(n*sqrt(n))", 21);
    else if (strat == COMPLEX)
        write(2, "Complex / O(n log n)", 20);
    else
    {
        write(2, "Adaptive / ", 11);
        if (disorder < 0.2)
            write(2, "O(n^2)", 6);
        else if (disorder >= 0.2 && disorder < 0.5)
            write(2, "O(n*sqrt(n))", 12);
        else
            write(2, "O(n log n)", 10);    
    }
    write(2, "\n", 1); 
}

void benchmark(double disorder, t_strategy strat)
{
    bench_disorder(disorder);
    bench_strategy(strat, disorder);
    
}