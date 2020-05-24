#pragma once

#define STR_AND						"AND"
#define STR_OR						"OR"
#define STR_NOT						"NOT"
#define STR_NAND					"NAND"
#define STR_NOR						"NOR"
#define STR_XOR						"XOR"

#define STR_INPUT_HIGH				"INPUT_HIGH"
#define STR_INPUT_LOW				"INPUT_LOW"

#define STR_PROBE					"PROBE"
#define STR_INPUT_NODE				"INPUT_NODE"

#define STR_NODE					"NODE"

#define CHAR_COMMENT				'#'
#define CHAR_DESCRIPTION_SEPERATOR	':'
#define CHAR_SEPARATOR				','
#define CHAR_LINE_END				';'

#define PROPAGATION_DELAY 10

typedef enum {ENUM_INPUT_NODE, ENUM_LOGIC_NODE, ENUM_PROBE_NODE, ENUM_ERROR_TYPE} NodeType;
typedef enum {ENUM_INPUT, ENUM_OUTPUT} IoType;

typedef enum {LOW, HIGH, UNDF} IoState; //Order is important!