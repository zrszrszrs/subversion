/* Handy subroutines used throughout Subversion.
 *
 * ================================================================
 * Copyright (c) 2000 Collab.Net.  All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * 3. The end-user documentation included with the redistribution, if
 * any, must include the following acknowlegement: "This product includes
 * software developed by Collab.Net (http://www.Collab.Net/)."
 * Alternately, this acknowlegement may appear in the software itself, if
 * and wherever such third-party acknowlegements normally appear.
 * 
 * 4. The hosted project names must not be used to endorse or promote
 * products derived from this software without prior written
 * permission. For written permission, please contact info@collab.net.
 * 
 * 5. Products derived from this software may not use the "Tigris" name
 * nor may "Tigris" appear in their names without prior written
 * permission of Collab.Net.
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL COLLAB.NET OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ====================================================================
 * 
 * This software may consist of voluntary contributions made by many
 * individuals on behalf of Collab.Net.
 */


/* Malloc, but with built-in error checking. */
void *
svn_malloc (size_t len)
{
  void *buf;
  
  if ((buf = malloc (len)) == NULL)
    {
      char err[60];
      sprintf (err, "unable to allocate %lu bytes", (unsigned long) len);
      exit (1);   /* todo: use some custom exit function later */
    }
  
  /* Else. */
  
  return (buf);
}


/* Realloc, with built-in error checking. */
void *
svn_realloc (void *old, size_t new_len)
{
  char *new;
  
  /* Not all realloc()s guarantee that a NULL argument is like calling
     malloc(), but that's the behavior we want. */
  if (old == NULL)
    new = malloc (new_len);
  else
    new = realloc (old, new_len);
  
  if (new == NULL)
    {
      char err[60];
      sprintf (err, "unable to allocate %lu bytes", (unsigned long) new_len);
      exit (1);   /* todo: use some custom exit function later? */
    }

  /* Else. */

  return (new);
}


/* 
 * local variables:
 * eval: (load-file "../svn-dev.el")
 * end:
 */

