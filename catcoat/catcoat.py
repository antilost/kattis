#!/usr/bin/env python3

import sys
import itertools

name_to_code = {
	"Red": {
		"orange": [ "OO" ],
		"dilution": [ "DD", "Dd" ],
		"black": [ "BB", "bB", "Bb", "bb" ]
	},
	"Cream": {
		"orange": [ "OO" ],
		"dilution": [ "dd" ],
		"black": [ "BB", "bB", "Bb", "bb" ]
	},
	"Black": {
		"orange": [ "oo" ],
		"dilution": [ "DD", "Dd" ],
		"black": [ "BB", "Bb" ]
	},
	"Lilac": {
		"orange": [ "oo" ],
		"dilution": [ "dd" ],
		"black": [ "bb" ]
	},
	"Chocolate": {
		"orange": [ "oo" ],
		"dilution": [ "DD", "Dd" ],
		"black": [ "bb" ]
	},
	"Blue": {
		"orange": [ "oo" ],
		"dilution": [ "dd" ],
		"black": [ "BB", "Bb" ]
	},
	"Lilac-Cream Tortie": {
		"orange": [ "Oo" ],
		"dilution": [ "dd" ],
		"black": [ "bb" ]
	},
	"Blue-Cream Tortie": {
		"orange": [ "Oo" ],
		"dilution": [ "dd" ],
		"black": [ "BB", "Bb" ]
	},
	"Chocolate-Red Tortie": {
		"orange": [ "Oo" ],
		"dilution": [ "Dd", "DD" ],
		"black": [ "bb" ]
	},
	"Black-Red Tortie": {
		"orange": [ "Oo" ],
		"dilution": [ "DD", "Dd" ],
		"black": [ "BB", "Bb" ]
	}
}

def get_name_from_code(code):
	(o, d, b) = ( code[0:2], code[2:4], code[4:] )
	
	if o == "OO":
		if d == "D-":
			return "Red"
		else:
			return "Cream"
	elif o == "oo":
		if b == "B-":
			if d == "D-":
				return "Black"
			else:
				return "Blue"
		else:
			if d == "D-":
				return "Chocolate"
			else:
				return "Lilac"
	else:
		if b == "B-":
			if d == "D-":
				return "Black-Red Tortie"
			else:
				return "Blue-Cream Tortie"
		else:
			if d == "D-":
				return "Chocolate-Red Tortie"
			else:
				return "Lilac-Cream Tortie"

def get_prob(items):
	count = {}
	for i in items:
		if i in count:
			count[i] += 1
		else:
			count[i] = 1

	prob = {}
	for i in count.keys():
		prob[i] = count[i] / len(items)

	return prob;

def get_female_orange_prob(f_code, m_code):
	items = [ ]

	if f_code["orange"][0][0] != m_code["orange"][0][0]:
		items.append("Oo")
	else:
		items.append(f_code["orange"][0][0] * 2)

	if f_code["orange"][0][1] != m_code["orange"][0][0]:
		items.append("Oo")
	else:
		items.append(f_code["orange"][0][1] * 2)

	return get_prob(items)

def get_male_orange_prob(f_code):
	items = [ ]
	items.append(f_code["orange"][0][0] * 2)
	items.append(f_code["orange"][0][1] * 2)
	return get_prob(items)

def get_dilution_prob(f_code, m_code):
	f_double_prob = get_prob( f_code["dilution"] )
	f_prob = {}
	for double_d in f_double_prob.keys():
		for d in double_d:
			p = f_double_prob[double_d] / 2 # because of 2 genes in pair
			if d in f_prob:
				f_prob[d] += p
			else:
				f_prob[d] = p
	# repeat for m...
	m_double_prob = get_prob( m_code["dilution"] )
	m_prob = {}
	for double_d in m_double_prob.keys():
		for d in double_d:
			p = m_double_prob[double_d] / 2 # because of 2 genes in pair
			if d in m_prob:
				m_prob[d] += p
			else:
				m_prob[d] = p

	prob = {}
	for df in f_prob.keys():
		for dm in m_prob.keys():
			p = f_prob[df] * m_prob[dm]
			gen = "D-" if (dm == "D") or (df == "D") else "dd"
			if gen in prob:
				prob[gen] += p
			else:
				prob[gen] = p
	return prob

def get_black_prob(f_code, m_code):
	f_double_prob = get_prob( f_code["black"] )
	f_prob = {}
	for double_b in f_double_prob.keys():
		for b in double_b:
			p = f_double_prob[double_b] / 2 # because of 2 genes in pair
			if b in f_prob:
				f_prob[b] += p
			else:
				f_prob[b] = p
	# repeat for m...
	m_double_prob = get_prob( m_code["black"] )
	m_prob = {}
	for double_b in m_double_prob.keys():
		for b in double_b:
			p = m_double_prob[double_b] / 2 # because of 2 genes in pair
			if b in m_prob:
				m_prob[b] += p
			else:
				m_prob[b] = p

	prob = {}
	for bf in f_prob.keys():
		for bm in m_prob.keys():
			p = f_prob[bf] * m_prob[bm]
			gen = "B-" if (bm == "B") or (bf == "B") else "bb"
			if gen in prob:
				prob[gen] += p
			else:
				prob[gen] = p
	return prob

(f_code, m_code) = map(lambda x: name_to_code[x.rstrip()], sys.stdin.readlines())

offspring = {}

sex_prob = 0.5
female_orange_prob = get_female_orange_prob(f_code, m_code)
male_orange_prob = get_male_orange_prob(f_code)
dilution_prob = get_dilution_prob(f_code, m_code)
black_prob = get_black_prob(f_code, m_code)

#print(female_orange_prob)
#print(male_orange_prob)
#print(dilution_prob)
#print(black_prob)

for o in female_orange_prob.keys():
	if o == "OO":
		for d in dilution_prob.keys():
			name = get_name_from_code(o + d + "uu")
			prob = sex_prob * female_orange_prob[o] * dilution_prob[d]
			if name in offspring:
				offspring[name] += prob
			else:
				offspring[name] = prob
	else:
		for d in dilution_prob.keys():
			for b in black_prob.keys():
				name = get_name_from_code(o + d + b)
				prob = sex_prob * female_orange_prob[o] * dilution_prob[d] * black_prob[b]
				if name in offspring:
					offspring[name] += prob
				else:
					offspring[name] = prob

for o in male_orange_prob.keys():
	if o == "OO":
		for d in dilution_prob.keys():
			name = get_name_from_code(o + d + "uu")
			prob = sex_prob * male_orange_prob[o] * dilution_prob[d]
			if name in offspring:
				offspring[name] += prob
			else:
				offspring[name] = prob
	else:
		for d in dilution_prob.keys():
			for b in black_prob.keys():
				name = get_name_from_code(o + d + b)
				prob = sex_prob * male_orange_prob[o] * dilution_prob[d] * black_prob[b]
				if name in offspring:
					offspring[name] += prob
				else:
					offspring[name] = prob

for o in sorted(offspring.items(), key=lambda item: (-item[1], item[0])):
	print("%s %.9f" % o)

