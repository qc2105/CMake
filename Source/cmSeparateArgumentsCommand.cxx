/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "cmSeparateArgumentsCommand.h"

// cmSeparateArgumentsCommand
bool cmSeparateArgumentsCommand::InitialPass(std::vector<std::string> const& args)
{
  if(args.size() != 1 )
    {
    this->SetError("called with incorrect number of arguments");
    return false;
    }
  const char* cacheValue = m_Makefile->GetDefinition(args[0].c_str());
  if(!cacheValue)
    {
    return true;
    }
  std::string value = cacheValue;
  cmSystemTools::ReplaceString(value,
                               " ", ";");
  m_Makefile->AddDefinition(args[0].c_str(), value.c_str());
  return true;
}

