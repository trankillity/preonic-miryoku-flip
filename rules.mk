TAP_DANCE_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
ENCODER_ENABLE = no
MOUSEKEY_ENABLE = yes
CAPSWORD_ENABLE = yes

ifeq ($(CAPSWORD_ENABLE), yes)
	OPT_DEFS += -DCAPSWORD_ENABLE
endif