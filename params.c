#include "main.h"

/**
 * init_params - clear the structure and reset
 * @params: the parameters
 * @args: the arguments
 *
 * Return: Always 0
*/
void init_params(params_t *params, va_list args)
{
	params->unsign = 0;
	params->h_modifier = 0;
	params->hashtag_flag = 0;
	params->l_modifier = 0;
	params->minus_flag = 0;
	params->plus_flag = 0;
	params->precision = 4294967295;
	params->space_flag = 0;
	params->width = 0;
	params->zero_flag = 0;
	(void)args;
}
