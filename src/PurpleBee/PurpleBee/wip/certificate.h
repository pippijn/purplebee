void
purple_certificate_verify (PurpleCertificateVerifier* verifier, gchar const* subject_name, GList* cert_chain, PurpleCertificateVerifiedCallback cb, gpointer cb_data);

void
purple_certificate_verify_complete (PurpleCertificateVerificationRequest* vrq, PurpleCertificateVerificationStatus st);

PurpleCertificate*
purple_certificate_copy (PurpleCertificate* crt);

GList*
purple_certificate_copy_list (GList* crt_list);

void
purple_certificate_destroy (PurpleCertificate* crt);

void
purple_certificate_destroy_list (GList* crt_list);

gboolean
purple_certificate_signed_by (PurpleCertificate* crt, PurpleCertificate* issuer);

gboolean
purple_certificate_check_signature_chain_with_failing (GList* chain, PurpleCertificate** failing);

gboolean
purple_certificate_check_signature_chain (GList* chain);

PurpleCertificate*
purple_certificate_import (PurpleCertificateScheme* scheme, gchar const* filename);

gboolean
purple_certificate_export (gchar const* filename, PurpleCertificate* crt);

GByteArray*
purple_certificate_get_fingerprint_sha1 (PurpleCertificate* crt);

gchar*
purple_certificate_get_unique_id (PurpleCertificate* crt);

gchar*
purple_certificate_get_issuer_unique_id (PurpleCertificate* crt);

gchar*
purple_certificate_get_subject_name (PurpleCertificate* crt);

gboolean
purple_certificate_check_subject_name (PurpleCertificate* crt, gchar const* name);

gboolean
purple_certificate_get_times (PurpleCertificate* crt, time_t* activation, time_t* expiration);

gchar*
purple_certificate_pool_mkpath (PurpleCertificatePool* pool, gchar const* id);

gboolean
purple_certificate_pool_usable (PurpleCertificatePool* pool);

PurpleCertificateScheme*
purple_certificate_pool_get_scheme (PurpleCertificatePool* pool);

gboolean
purple_certificate_pool_contains (PurpleCertificatePool* pool, gchar const* id);

PurpleCertificate*
purple_certificate_pool_retrieve (PurpleCertificatePool* pool, gchar const* id);

gboolean
purple_certificate_pool_store (PurpleCertificatePool* pool, gchar const* id, PurpleCertificate* crt);

gboolean
purple_certificate_pool_delete (PurpleCertificatePool* pool, gchar const* id);

GList*
purple_certificate_pool_get_idlist (PurpleCertificatePool* pool);

void
purple_certificate_pool_destroy_idlist (GList* idlist);

void
purple_certificate_init ();

void
purple_certificate_uninit ();

gpointer
purple_certificate_get_handle ();

PurpleCertificateScheme*
purple_certificate_find_scheme (gchar const* name);

GList*
purple_certificate_get_schemes ();

gboolean
purple_certificate_register_scheme (PurpleCertificateScheme* scheme);

gboolean
purple_certificate_unregister_scheme (PurpleCertificateScheme* scheme);

PurpleCertificateVerifier*
purple_certificate_find_verifier (gchar const* scheme_name, gchar const* ver_name);

GList*
purple_certificate_get_verifiers ();

gboolean
purple_certificate_register_verifier (PurpleCertificateVerifier* vr);

gboolean
purple_certificate_unregister_verifier (PurpleCertificateVerifier* vr);

PurpleCertificatePool*
purple_certificate_find_pool (gchar const* scheme_name, gchar const* pool_name);

GList*
purple_certificate_get_pools ();

gboolean
purple_certificate_register_pool (PurpleCertificatePool* pool);

gboolean
purple_certificate_unregister_pool (PurpleCertificatePool* pool);

void
purple_certificate_display_x509 (PurpleCertificate* crt);

void
purple_certificate_add_ca_search_path (char const* path);
