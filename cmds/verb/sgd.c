inherit CMD;

private void main(mixed *arg)
{
    
    this_body()->query_shell_ob()->set_pwd("/sgdomain");

    outf("µ±Ç°Ä¿Â¼: \\sgdomain\n", );
}
array query_verb_info()
{
    return ({ ({ ""}),({  }) });
}
