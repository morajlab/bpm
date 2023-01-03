.PHONY: clean

OBJECTS = cli.c parser.c request.c schema.c libmjl-cpp/src/create_chain/create_chain.c
FLAGS = -lcurl
ODIR = build

# TODO: Improve 'create_chain.c' path
cli: $(OBJECTS)
	gcc -o $(ODIR)/cli $(OBJECTS) $(FLAGS)

clean:
	rm -rf *.out $(ODIR)/
	mkdir $(ODIR)
