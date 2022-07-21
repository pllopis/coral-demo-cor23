CC := gcc
CCFLAGS := -Og -g -fno-omit-frame-pointer -fopenmp
VEC_CCFLAGS := -g -fno-omit-frame-pointer -O3 -march=native -ffast-math -ftree-vectorize -fopenmp

OBJ := sum-serial sum-para sum-para-small sum-para-vec mult-vec mult-many mult-many-aos

default: all

.PHONY: clean
clean:
	@rm -rf $(OBJ)

.PHONY: all
all: $(OBJ)

sum-serial: sum-serial.c
	$(CC) $(CCFLAGS) -o $@ $<

mult: mult.c
	$(CC) $(CCFLAGS) -o $@ $<

sum-para: sum-para.c
	$(CC) $(CCFLAGS) -o $@ $<

sum-para-small: sum-para-small.c
	$(CC) $(VEC_CCFLAGS) -o $@ $<

m: m.c
	$(CC) $(VEC_CCFLAGS) -o $@ $<

mult-vec: mult.c
	$(CC) $(VEC_CCFLAGS) -o $@ $<

sum-para-vec: sum-para.c
	$(CC) $(VEC_CCFLAGS) -o $@ $<

mult-many: mult-many.c
	$(CC) $(VEC_CCFLAGS) -o $@ $<

mult-many-aos: mult-many-aos.c
	$(CC) $(VEC_CCFLAGS) -o $@ $<

.PHONY: full-profile
full-profile: roofline map dependencies

.PHONY: roofline
roofline:
ifndef program
	$(error Use with program=program_name)
endif
	advixe-cl -collect roofline --enable-cache-simulation -project-dir "profile-$(program)" -- ./$(program)

.PHONY: map
map:
ifndef program
	$(error Use with program=program_name)
endif
	advixe-cl -collect map -project-dir "profile-$(program)" -- ./$(program)

.PHONY: depencies
dependencies:
ifndef program
	$(error Use with program=program_name)
endif
	advixe-cl -collect dependencies -project-dir "profile-$(program)" -- ./$(program)

