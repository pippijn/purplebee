package PurpleBee::UiOps::Core;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub ui_prefs_init {
   my ($self) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Core::ui_prefs_init";
}

sub debug_ui_init {
   my ($self) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Core::debug_ui_init";
   $self->valgrind;
}

sub ui_init {
   my ($self) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Core::ui_init";
}

sub quit {
   my ($self) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Core::quit";
}

# Returns a hash table containing various information about the UI.  The
# following well-known entries may be in the table (along with any others the
# UI might choose to include):
#
# <dl>
#   <dt><tt>name</tt></dt>
#   <dd>the user-readable name for the UI.</dd>
#
#   <dt><tt>version</tt></dt>
#   <dd>a user-readable description of the current version of the UI.</dd>
#
#   <dt><tt>website</tt></dt>
#   <dd>the UI's website, such as http://pidgin.im.</dd>
#
#   <dt><tt>dev_website</tt></dt>
#   <dd>the UI's development/support website, such as http://developer.pidgin.im.</dd>
#
#   <dt><tt>client_type</tt></dt>
#   <dd>the type of UI. Possible values include 'pc', 'console', 'phone',
#       'handheld', 'web', and 'bot'. These values are compared
#       programmatically and should not be localized.</dd>
#   
# </dl>
#
# @return A GHashTable with strings for keys and values.  This
# hash table must not be freed and should not be modified.
#
# @since 2.1.0
sub get_ui_info {
   my ($self) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Core::get_ui_info";

   {
      name 	  => PurpleBee::PACKAGE_NAME,
      version 	  => PurpleBee::PACKAGE_VERSION,
      website 	  => PurpleBee::PACKAGE_URL,
      dev_website => PurpleBee::PACKAGE_URL,
      client_type => 'console',
   }
}


1
