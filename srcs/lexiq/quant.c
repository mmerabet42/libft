#include "lexiq.h"

t_lq_quant lq_quant(int min, int max)
{
	t_lq_quant quant;

	quant.min_var = 0;
	quant.min = min;
	quant.max_var = 0;
	quant.max = max;
	return quant;
} 

t_lq_quant lq_quant0(int min, int max)
{
	t_lq_quant quant;

	quant.min_var = 1;
	quant.min = min;
	quant.max_var = 0;
	quant.max = max;
	return quant;
} 

t_lq_quant lq_quant1(int min, int max)
{
	t_lq_quant quant;

	quant.min_var = 0;
	quant.min = min;
	quant.max_var = 1;
	quant.max = max;
	return quant;
} 

t_lq_quant lq_quant2(int min, int max)
{
	t_lq_quant quant;

	quant.min_var = 1;
	quant.min = min;
	quant.max_var = 1;
	quant.max = max;
	return quant;
} 
