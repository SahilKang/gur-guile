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
#include <gurmukhi.hpp>

template<typename T>
static SCM get_func(const SCM &args, const T &func)
{
	const char* const str = scm_to_utf8_stringn(args, NULL);
	SCM g_str = scm_from_utf8_string(func(str));

	free(const_cast<char*>(str));
	return g_str;
}

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
	return get_func(args,
		(const char* (*)(const char* const&))&gur::letters);
}

static SCM gg_accents(SCM args)
{
	return get_func(args,
		(const char* (*)(const char* const&))&gur::accents);
}

static SCM gg_puncs(SCM args)
{
	return get_func(args,
		(const char* (*)(const char* const&))&gur::puncs);
}

static SCM gg_digits(SCM args)
{
	return get_func(args,
		(const char* (*)(const char* const&))&gur::digits);
}

static SCM gg_symbols(SCM args)
{
	return get_func(args,
		(const char* (*)(const char* const&))&gur::symbols);
}

static SCM gg_comp(SCM args)
{
	return get_func(args,
		(const char* (*)(const char* const&))&gur::comp);
}

static SCM gg_clobber(SCM args)
{
	return get_func(args,
		(const char* (*)(const char* const&))&gur::clobber);
}

static SCM gg_unclobber(SCM args)
{
	return get_func(args,
		(const char* (*)(const char* const&))&gur::unclobber);
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

	scm_c_define("gur-a1", scm_from_utf8_string(gur::A1));
	scm_c_define("gur-a2", scm_from_utf8_string(gur::A2));
	scm_c_define("gur-a3", scm_from_utf8_string(gur::A3));
	scm_c_define("gur-a4", scm_from_utf8_string(gur::A4));
	scm_c_define("gur-a5", scm_from_utf8_string(gur::A5));

	scm_c_define("gur-b1", scm_from_utf8_string(gur::B1));
	scm_c_define("gur-b2", scm_from_utf8_string(gur::B2));
	scm_c_define("gur-b3", scm_from_utf8_string(gur::B3));
	scm_c_define("gur-b4", scm_from_utf8_string(gur::B4));
	scm_c_define("gur-b5", scm_from_utf8_string(gur::B5));

	scm_c_define("gur-c1", scm_from_utf8_string(gur::C1));
	scm_c_define("gur-c2", scm_from_utf8_string(gur::C2));
	scm_c_define("gur-c3", scm_from_utf8_string(gur::C3));
	scm_c_define("gur-c4", scm_from_utf8_string(gur::C4));
	scm_c_define("gur-c5", scm_from_utf8_string(gur::C5));

	scm_c_define("gur-d1", scm_from_utf8_string(gur::D1));
	scm_c_define("gur-d2", scm_from_utf8_string(gur::D2));
	scm_c_define("gur-d3", scm_from_utf8_string(gur::D3));
	scm_c_define("gur-d4", scm_from_utf8_string(gur::D4));
	scm_c_define("gur-d5", scm_from_utf8_string(gur::D5));

	scm_c_define("gur-e1", scm_from_utf8_string(gur::E1));
	scm_c_define("gur-e2", scm_from_utf8_string(gur::E2));
	scm_c_define("gur-e3", scm_from_utf8_string(gur::E3));
	scm_c_define("gur-e4", scm_from_utf8_string(gur::E4));
	scm_c_define("gur-e5", scm_from_utf8_string(gur::E5));

	scm_c_define("gur-f1", scm_from_utf8_string(gur::F1));
	scm_c_define("gur-f2", scm_from_utf8_string(gur::F2));
	scm_c_define("gur-f3", scm_from_utf8_string(gur::F3));
	scm_c_define("gur-f4", scm_from_utf8_string(gur::F4));
	scm_c_define("gur-f5", scm_from_utf8_string(gur::F5));

	scm_c_define("gur-g1", scm_from_utf8_string(gur::G1));
	scm_c_define("gur-g2", scm_from_utf8_string(gur::G2));
	scm_c_define("gur-g3", scm_from_utf8_string(gur::G3));
	scm_c_define("gur-g4", scm_from_utf8_string(gur::G4));
	scm_c_define("gur-g5", scm_from_utf8_string(gur::G5));

	scm_c_define("gur-h1", scm_from_utf8_string(gur::H1));
	scm_c_define("gur-h2", scm_from_utf8_string(gur::H2));
	scm_c_define("gur-h3", scm_from_utf8_string(gur::H3));
	scm_c_define("gur-h4", scm_from_utf8_string(gur::H4));
	scm_c_define("gur-h5", scm_from_utf8_string(gur::H5));

	scm_c_define("gur-i1", scm_from_utf8_string(gur::I1));
	scm_c_define("gur-i2", scm_from_utf8_string(gur::I2));
	scm_c_define("gur-i3", scm_from_utf8_string(gur::I3));
	scm_c_define("gur-i4", scm_from_utf8_string(gur::I4));
	scm_c_define("gur-i5", scm_from_utf8_string(gur::I5));

	scm_c_define("gur-j1", scm_from_utf8_string(gur::J1));
	scm_c_define("gur-j2", scm_from_utf8_string(gur::J2));
	scm_c_define("gur-j3", scm_from_utf8_string(gur::J3));
	scm_c_define("gur-j4", scm_from_utf8_string(gur::J4));
	scm_c_define("gur-j5", scm_from_utf8_string(gur::J5));

	scm_c_define("gur-k1", scm_from_utf8_string(gur::K1));
	scm_c_define("gur-k2", scm_from_utf8_string(gur::K2));
	scm_c_define("gur-k3", scm_from_utf8_string(gur::K3));
	scm_c_define("gur-k4", scm_from_utf8_string(gur::K4));
	scm_c_define("gur-k5", scm_from_utf8_string(gur::K5));

	scm_c_define("gur-l1", scm_from_utf8_string(gur::L1));
	scm_c_define("gur-l2", scm_from_utf8_string(gur::L2));
	scm_c_define("gur-l3", scm_from_utf8_string(gur::L3));
	scm_c_define("gur-l4", scm_from_utf8_string(gur::L4));
	scm_c_define("gur-l5", scm_from_utf8_string(gur::L5));

	scm_c_define("gur-m1", scm_from_utf8_string(gur::M1));
	scm_c_define("gur-m2", scm_from_utf8_string(gur::M2));
	scm_c_define("gur-m3", scm_from_utf8_string(gur::M3));
	scm_c_define("gur-m4", scm_from_utf8_string(gur::M4));
	scm_c_define("gur-m5", scm_from_utf8_string(gur::M5));

	scm_c_define("gur-n1", scm_from_utf8_string(gur::N1));
	scm_c_define("gur-n2", scm_from_utf8_string(gur::N2));
	scm_c_define("gur-n3", scm_from_utf8_string(gur::N3));
	scm_c_define("gur-n4", scm_from_utf8_string(gur::N4));
	scm_c_define("gur-n5", scm_from_utf8_string(gur::N5));

	scm_c_define("gur-o1", scm_from_utf8_string(gur::O1));
	scm_c_define("gur-o2", scm_from_utf8_string(gur::O2));
	scm_c_define("gur-o3", scm_from_utf8_string(gur::O3));
	scm_c_define("gur-o4", scm_from_utf8_string(gur::O4));
	scm_c_define("gur-o5", scm_from_utf8_string(gur::O5));

	scm_c_define("gur-p1", scm_from_utf8_string(gur::P1));
	scm_c_define("gur-p2", scm_from_utf8_string(gur::P2));
	scm_c_define("gur-p3", scm_from_utf8_string(gur::P3));
	scm_c_define("gur-p4", scm_from_utf8_string(gur::P4));
	scm_c_define("gur-p5", scm_from_utf8_string(gur::P5));

	scm_c_define("gur-q1", scm_from_utf8_string(gur::Q1));
	scm_c_define("gur-q2", scm_from_utf8_string(gur::Q2));

	scm_c_export("letters", "accents", "puncs", "digits", "symbols", NULL);
	scm_c_export("comp", "clobber", "unclobber", NULL);
	scm_c_export("is-letter", "is-accent", "is-punc", "is-digit",
		"is-symbol", NULL);
	scm_c_export(	"gur-a1", "gur-a2", "gur-a3", "gur-a4", "gur-a5",
			"gur-b1", "gur-b2", "gur-b3", "gur-b4", "gur-b5",
			"gur-c1", "gur-c2", "gur-c3", "gur-c4", "gur-c5",
			"gur-d1", "gur-d2", "gur-d3", "gur-d4", "gur-d5",
			"gur-e1", "gur-e2", "gur-e3", "gur-e4", "gur-e5",
			"gur-f1", "gur-f2", "gur-f3", "gur-f4", "gur-f5",
			"gur-g1", "gur-g2", "gur-g3", "gur-g4", "gur-g5",
			"gur-h1", "gur-h2", "gur-h3", "gur-h4", "gur-h5",
			"gur-i1", "gur-i2", "gur-i3", "gur-i4", "gur-i5",
			"gur-j1", "gur-j2", "gur-j3", "gur-j4", "gur-j5",
			"gur-k1", "gur-k2", "gur-k3", "gur-k4", "gur-k5",
			"gur-l1", "gur-l2", "gur-l3", "gur-l4", "gur-l5",
			"gur-m1", "gur-m2", "gur-m3", "gur-m4", "gur-m5",
			"gur-n1", "gur-n2", "gur-n3", "gur-n4", "gur-n5",
			"gur-o1", "gur-o2", "gur-o3", "gur-o4", "gur-o5",
			"gur-p1", "gur-p2", "gur-p3", "gur-p4", "gur-p5",
			"gur-q1", "gur-q2",
			NULL);
}

extern "C"
{
	void scm_init_gur_guile_module()
	{
		scm_c_define_module("gur-guile", init_gur_guile, NULL);
	}
}
