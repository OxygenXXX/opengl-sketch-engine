#version 330 core

out vec4 fragment_color;

void main(void)
{
    if(gl_FragCoord.x < 400)
    {
        fragment_color = vec4(0.0, 0.0, 1.0, 1.0);
    }

    if(gl_FragCoord.x > 400)
    {
        fragment_color = vec4(0.0, 1.0, 0.0, 1.0);    
    }        
}