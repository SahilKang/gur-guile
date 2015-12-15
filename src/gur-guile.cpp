/******************************************************************************
 * Copyright (C) 2015 Sahil Kang <sahil.kang@asilaycomputing.com>
 *
 * This file is part of gur-guile.
 *
 * gur-guile is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * gur-guile is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with gur-guile.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <libguile.h>
#include <gur.hpp>

template<typename T>
static SCM is_type(const SCM &args, const T &func)
{
	const char* const str = scm_to_utf8_stringn(args, NULL);
	bool is_type = func(str);

	free(const_cast<char*>(str));

	if (is_type)
	{
		return SCM_BOOL_T;
	}

	else
	{
		return SCM_BOOL_F;
	}
}

static SCM gg_letters(SCM args)
{
	const char* const str = scm_to_utf8_stringn(args, NULL);
	SCM g_str = scm_from_utf8_string(gur::letters(str));

	free(const_cast<char*>(str));
	return g_str;
}

static SCM gg_accents(SCM args)
{
	const char* const str = scm_to_utf8_stringn(args, NULL);
	SCM g_str = scm_from_utf8_string(gur::accents(str));

	free(const_cast<char*>(str));
	return g_str;
}

static SCM gg_puncs(SCM args)
{
	const char* const str = scm_to_utf8_stringn(args, NULL);
	SCM g_str = scm_from_utf8_string(gur::puncs(str));

	free(const_cast<char*>(str));
	return g_str;
}

static SCM gg_digits(SCM args)
{
	const char* const str = scm_to_utf8_stringn(args, NULL);
	SCM g_str = scm_from_utf8_string(gur::digits(str));

	free(const_cast<char*>(str));
	return g_str;
}

static SCM gg_symbols(SCM args)
{
	const char* const str = scm_to_utf8_stringn(args, NULL);
	SCM g_str = scm_from_utf8_string(gur::symbols(str));

	free(const_cast<char*>(str));
	return g_str;
}

static SCM gg_comp(SCM args)
{
	const char* const str = scm_to_utf8_stringn(args, NULL);
	SCM g_str = scm_from_utf8_string(gur::comp(str));

	free(const_cast<char*>(str));
	return g_str;
}

static SCM gg_clobber(SCM args)
{
	const char* const str = scm_to_utf8_stringn(args, NULL);
	SCM g_str = scm_from_utf8_string(gur::clobber(str));

	free(const_cast<char*>(str));
	return g_str;
}

static SCM gg_unclobber(SCM args)
{
	const char* const str = scm_to_utf8_stringn(args, NULL);
	SCM g_str = scm_from_utf8_string(gur::unclobber(str));

	free(const_cast<char*>(str));
	return g_str;
}

static SCM gg_is_letter(SCM args)
{
	return is_type(args, (bool (*)(const char* const&))&gur::is_letter);
}

static SCM gg_is_accent(SCM args)
{
	return is_type(args, (bool (*)(const char* const&))&gur::is_accent);
}

static SCM gg_is_punc(SCM args)
{
	return is_type(args, (bool (*)(const char* const&))&gur::is_punc);
}

static SCM gg_is_digit(SCM args)
{
	return is_type(args, (bool (*)(const char* const&))&gur::is_digit);
}

static SCM gg_is_symbol(SCM args)
{
	return is_type(args, (bool (*)(const char* const&))&gur::is_symbol);
}

static void init_gur_guile(void *unused)
{
	scm_c_define_gsubr("letters", 1, 0, 0, (scm_t_subr)&gg_letters);
	scm_c_define_gsubr("accents", 1, 0, 0, (scm_t_subr)&gg_accents);
	scm_c_define_gsubr("puncs", 1, 0, 0, (scm_t_subr)&gg_puncs);
	scm_c_define_gsubr("digits", 1, 0, 0, (scm_t_subr)&gg_digits);
	scm_c_define_gsubr("symbols", 1, 0, 0, (scm_t_subr)&gg_symbols);
	scm_c_define_gsubr("comp", 1, 0, 0, (scm_t_subr)&gg_comp);
	scm_c_define_gsubr("clobber", 1, 0, 0, (scm_t_subr)&gg_clobber);
	scm_c_define_gsubr("unclobber", 1, 0, 0, (scm_t_subr)&gg_unclobber);
	scm_c_define_gsubr("is-letter", 1, 0, 0, (scm_t_subr)&gg_is_letter);
	scm_c_define_gsubr("is-accent", 1, 0, 0, (scm_t_subr)&gg_is_accent);
	scm_c_define_gsubr("is-punc", 1, 0, 0, (scm_t_subr)&gg_is_punc);
	scm_c_define_gsubr("is-digit", 1, 0, 0, (scm_t_subr)&gg_is_digit);
	scm_c_define_gsubr("is-symbol", 1, 0, 0, (scm_t_subr)&gg_is_symbol);

	scm_c_export("letters", NULL);
	scm_c_export("accents", NULL);
	scm_c_export("puncs", NULL);
	scm_c_export("digits", NULL);
	scm_c_export("symbols", NULL);
	scm_c_export("comp", NULL);
	scm_c_export("clobber", NULL);
	scm_c_export("unclobber", NULL);
	scm_c_export("is-letter", NULL);
	scm_c_export("is-accent", NULL);
	scm_c_export("is-punc", NULL);
	scm_c_export("is-digit", NULL);
	scm_c_export("is-symbol", NULL);
}

extern "C"
{
	void scm_init_gur_guile_module()
	{
		scm_c_define_module("gur-guile", init_gur_guile, NULL);
	}
}
