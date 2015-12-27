/* help.c */
PRIVATE void PROCEDURE()
{
    Entry *i = symtabindex;
    int column = 0, name_length;

    while (--i != symtab)
	if (i->name[0] REL '_' && !i->is_local) {
	    name_length = strlen(i->name) + 1;
	    if (column + name_length > 72) {
		printf("\n");
		column = 0;
	    }
	    printf("%s ", i->name);
	    column += name_length;
	}
    printf("\n");
}

#undef PROCEDURE
#undef REL
